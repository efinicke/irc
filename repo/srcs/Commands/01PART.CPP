/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01PART.CPP                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 04:26:58 by efinicke          #+#    #+#             */
/*   Updated: 2023/01/29 12:48:25 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
 
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


void    part(Command &command, Server &server)
{
        
        User        *user = server.findUser(command.getClientSfd());
        Channel     *channel;
        std::string channelName;
        int         size = command.getChannels().size();

        if (size == 0) //si pas de channel précisé
            server.sendMsg(ERR_NEEDMOREPARAMS(user->getHostname(), user->getUserSfd()), command.getClientSfd());
        else if (size > 0)
        {
            for (int i = 0; i < size; i++){ //traiter tous les channels précisés. 
                channelName = command.getChannels()[i];
                if ((channel = server.findChannel(channelName)) == NULL){ // si le channel n'existe pas
                    server.sendMsg(ERR_NOSUCHCHANNEL(user->getHostname(), user->getNickname()), command.getClientSfd());
                }
                else if (user->findChannel(channelName) == 0){ // si l'utilisateur n'est pas sur le channel
                    server.sendMsg(ERR_NOTONCHANNEL(user->getHostname(), channel->getName()), command.getClientSfd());
                }
                else{
                    user->removeChannel(channelName);  // supprimer de la liste des channels de l'utilisateur
                    channel->removeUser(command.getClientSfd(), channel->getUsersMap());// supprimer l'utilisateur du channel.
                    channel->removeUser(command.getClientSfd(), channel->getOperatorsMap());// supprimer de la liste des opérateurs.
                    
                    
                    channel->sendAllUsers(PART(user->getHostname(), channel->getName(), channel->getName()), command.getClientSfd()); //informer les users
                    
                    if (channel->getUsersMap().size() == 0 || (channel->getUsersMap().size() == 1) && ((channel->getUsersMap()[0].getNickname()) == user->getNickname()))
                        server.removeIRCChannel(channelName); // si la liste des users du channel est vide, supprimer le channel a partir du serveur.
                }
            }
        }
}