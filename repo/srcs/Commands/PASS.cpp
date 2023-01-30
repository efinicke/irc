/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PASS.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:54:15 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/27 01:07:11 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Include.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Parsing.hpp"

void	pass_cmd(command *cmd, Server *ircServ)
{
	std::vector<std::string>	pw = cmd->getmessage();
	if (pw[0] == ircServ->getPassword())
		std::cout << GREEN << "good password" << RESET << std::endl;
	else
	{
		
		std::string	error = "Pass :Password incorrect\r\n";
		int size = error.size();
		send(cmd->getClientSfd(), error.c_str(), size, 0);
	}
	// ERR_PASSWDMISMATCH
}
