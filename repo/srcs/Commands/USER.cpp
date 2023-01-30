/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   USER.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:07:37 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/27 01:07:31 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Include.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Parsing.hpp"

void	user_cmd(std::string hostname, std::string nickname, command *cmd, Server *ircServ)
{
	std::vector<std::string>	vect = cmd->getnickname();
	std::string					username = vect.front();
	vect = cmd->getserver();
	std::string					servername = vect.front();
	vect = cmd->getmessage();
	std::string					realname = vect.front();

	ircServ->add_user(nickname, username, hostname, servername, realname, cmd->getClientSfd());
	std::cout << *ircServ << std::endl;
}
