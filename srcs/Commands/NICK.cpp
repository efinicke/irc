/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NICK.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 04:27:02 by efinicke          #+#    #+#             */
/*   Updated: 2023/01/30 03:28:14 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "../../includes/Include.hpp"
 # include "../../includes/User.hpp"
 # include "../../includes/Server.hpp"


class	Command
{
    private:
    std::vector<std::string>    _channel; 	// cmd argument
    std::vector<std::string>    _nickname; 	// cmd argument
    std::vector<std::string>    _server; 	// cmd argument
    std::vector<std::string>    _message; 	// cmd argument
    int                         _clientSfd; // socket file descriptor du client émetteur

	public:
    std::vector<std::string> getchannels();
    std::vector<std::string> getnickname();
    std::vector<std::string> getserver();
    std::vector<std::string> getmessage();
	int						 getClientSfd();
};

// transformer le nick en minuscules?
int	 isValidNickname(std::string nickname){
	int i = -1;
	char c = nickname.c_str()[0];
	char str[] = {',',' ','\r','\n','\a','\0','#','&'};
	
	while(str[++i]){
		if (nickname.find(str[i])!= std::string::npos)
			return (0);
	}
	if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
		return (0);
	if (nickname.length() > 9)
		return (0);
	return (1);
}


void nick(Command &command, Server &server)
{
	User *user = server.findUser(command.getClientSfd());

    if (command.getnickname().size() == 0)
		server.sendMsg(ERR_NONICKNAMEGIVEN(user->getHostname()), command.getClientSfd());
	else if (command.getnickname().size() > 0)
	{
		if (server.findUser(command.getnickname()[0]) != NULL)
			server.sendMsg(ERR_NICKNAMEINUSE(user->getHostname(), user->getNickname()), command.getClientSfd());
		else if (!isValidNickname(command.getnickname()[0]))
			server.sendMsg(ERR_ERRONEUSNICKNAME(user->getHostname(), user->getNickname()), command.getClientSfd());
		else
		{
			user->setNickname(command.getnickname()[0]); // changer le nom de l'utilisateur
			server.sendMsg(NICK(user->getHostname(), user->getNickname()), command.getClientSfd());
			user->sendMsgInAllChannels();
		}
	}
}