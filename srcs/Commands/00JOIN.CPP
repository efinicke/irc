/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00JOIN.CPP                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 04:26:49 by efinicke          #+#    #+#             */
/*   Updated: 2023/01/30 07:48:54 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "../../includes/Include.hpp"
 # include "../../includes/User.hpp"
 # include "../../includes/Server.hpp"
 # include "../../includes/Channel.hpp"

class	Command
{
    private:
    std::vector<std::string>    _channel; 	// cmd argument
    std::vector<std::string>    _nickname; 	// cmd argument
    std::vector<std::string>    _server; 	// cmd argument
    std::vector<std::string>    _message; 	// cmd argument
    int                         _clientSfd; // socket file descriptor du client émetteur

	public:
    std::vector<std::string> getChannels();
    std::vector<std::string> getNickname();
    std::vector<std::string> getServer();
    std::vector<std::string> getMessage();
	int						 getClientSfd();
};

// enlever le #
// parser le channel pour le mettre en lowercase
// verifier le nom du channel, il faut qu'il soit conforme a la syntaxe acceptee dans le RFC

int             isValidChan(std::string channelName){
    if (channelName.c_str()[0] == '#') //il faut un # en premiere lettre
        return (1);
    return (0);
}

void    join(Command &command, Server &server)
{
    User        *user = server.findUser(command.getClientSfd());
    int         i;
    int         size = command.getChannels().size();
    Channel     *channel;
    std::string channelName;
    
    if (size == 0){ // si pas assez d'arguments
        server.sendMsg(ERR_NEEDMOREPARAMS(user->getHostname(), user->getUserSfd()), command.getClientSfd());
    }
    else if (size > 0) // 
    {
        for (i = 0; i < size ; i++)
        {
            channelName = command.getChannels()[i];
            if ((channel = server.findChannel(channelName)) != NULL) // si le channel existe déjà
            {
                if ((channel->getModes() & LIMITED_MODE) // si mode l (nbre de users limités)
                    && (channel->getUsersMap().size() == channel->getMaxUsers()) // et que le maximum d'utilisateurs est atteind
                    && (channel->findUser(command.getClientSfd(), channel->getInviteMap()) == NULL)) // et que l'user n'est pas invité
                    server.sendMsg(ERR_CHANNELISFULL(user->getHostname(), channel->getName()), command.getClientSfd()); // error
                else if (user->getChannels().size() == 10) // si le user est déjà sur le nbre max de chan autorisés
                    server.sendMsg(ERR_TOOMANYCHANNELS(user->getHostname(), channel->getName()), command.getClientSfd()); //error toomany chan
                else if (channel->findUser(command.getClientSfd(), channel->getBanMap()) != NULL) // s'il est banni
                    server.sendMsg(ERR_BANNEDFROMCHAN(user->getHostname(), channel->getName()), command.getClientSfd());
                else if ((channel->findUser(command.getClientSfd(), channel->getInviteMap()) == NULL) // s'il est pas invité
                    && (channel->getModes() & INVITE_MODE)) // et que le mode invité est activé
                    server.sendMsg(ERR_INVITEONLYCHAN(user->getHostname(), channel->getName()), command.getClientSfd()); //error
                else if ((channel->getModes() & KEY_MODE) // si un password est requis
                        && ((command.getMessage().size() == 0) // et que l'user n'a pas rentré de password
                        || (command.getMessage()[i] != channel->getPassword()))) // ou à rentré un password érroné
                        server.sendMsg(ERR_BADCHANNELKEY(user->getHostname(), channel->getName()), command.getClientSfd()); //error
                else
                {
                    channel->addUser(command.getClientSfd(), user); // ajouter l'user sur la liste des utilisateurs du channel
                    user->addChannel(channel->getName()); // ajouter le channel a la liste de l'utilisateur
                    channel->sendAllUsers(JOIN(user->getHostname(), channel->getName())); // informer tous les users du join
                    for (std::map< int, User *>::iterator it = channel->getUsersMap().begin(); it != channel->getUsersMap().end(); it++)
                            server.sendMsg(RPL_NAMREPLY(user->getHostname(), channel->getName(), it->second->getNickname()), command.getClientSfd()); // envoyer la liste de tous les noms des users
                    server.sendMsg(RPL_ENDOFNAMES(user->getHostname(), user->getNickname(), channel->getName()), command.getClientSfd()); //endofnames signal
                    // voir si on appelle MODE 
                    // voir si on appelle WHO
                }
            }
            else
            {
                if (command.getMessage().size() == 0) // si pas de password entré
                {
                    server.addIRCChannel(channelName); // créer un channel sans mot de passe
                    channel = server.findChannel(channelName); // l'attribuer au channel
                }
                else // si mot de passe
                {
                    server.addIRCChannel(channelName, command.getMessage()[i]); // créer un channel avec un mot de passe
                    channel = server.findChannel(channelName); // l'attribuer au channel
                    if (channel != NULL)
                    {
                        channel->addMode(KEY_MODE);
                        channel->setPassword(command.getMessage()[i]);
                    }
                }
                if (channel == NULL)
                {
                    server.sendMsg(ERR_UNAVAILRESOURCE(user->getHostname(), channel->getName()), command.getClientSfd());                   
                    return ;
                }
                channel->addUser(command.getClientSfd(), user); // ajouter l'user sur la liste des utilisateurs du channel
                channel->addOperator(command.getClientSfd(), user); // ajouter l'user sur la liste des opérateurs du channel, car il est le createur
                user->setNickname("@" + user->getNickname()); // mettre @ devant le nickname
                user->addChannel(channel->getName()); // ajouter le channel a la liste de l'utilisateur
                for (std::map< int, User *>::iterator it = channel->getUsersMap().begin(); it != channel->getUsersMap().end(); it++)
                    server.sendMsg(RPL_NAMREPLY(user->getHostname(), channel->getName(), it->second->getNickname()), command.getClientSfd()); //envoyer la liste de tous les noms des users
                channel->sendAllUsers(JOIN(user->getHostname(), channel->getName())); // informer tous les users du join
                server.sendMsg(RPL_ENDOFNAMES(user->getHostname(), user->getNickname(), channel->getName()), command.getClientSfd()); //endofnames signal
                for (std::map< int, User *>::iterator it = channel->getUsersMap().begin(); it != channel->getUsersMap().end(); it++)
                    server.sendMsg(RPL_NAMREPLY(user->getHostname(), channel->getName(), it->second->getNickname()), command.getClientSfd()); // envoyer la liste de tous les noms des users
                // voir si on appelle MODE 
                // voir si on appelle WHO
            }
        }
    }
}

// si on decide de rajouter le mode invisible de l'utilisateur, il ne devra pas apparaitre dans la liste NAMES.
// 
// MODE KICK &NAMES TOPIC &PART WHO &NICK

/*
==> JOIN #coco
<== :efinicke_!~efinicke@62.C06CDF75 JOIN #coco
<== :celestin.fr.ircube.org 353 efinicke_ = #coco :@efinicke_
<== :celestin.fr.ircube.org 366 efinicke_ #coco :End of /NAMES list.


==> MODE #coco  // seulement a la creation du channel 
<== :celestin.fr.ircube.org 324 efinicke_ #coco + 
<== :celestin.fr.ircube.org 329 efinicke_ #coco 1674983938

==> WHO #coco // pour la creation de l'user
<== :celestin.fr.ircube.org 352 efinicke_ #coco ~efinicke 62.C06CDF75 celestin.fr.ircube.org efinicke_ H@ :0 Elodie FINICKEL
<== :celestin.fr.ircube.org 315 efinicke_ #coco :End of /WHO list.*/