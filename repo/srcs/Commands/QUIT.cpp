/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QUIT.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:01:03 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/27 01:06:11 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Include.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Parsing.hpp"

void	quit_cmd(command *cmd, Server *ircServ)
{
	(void)ircServ;

	// if (cmd->get_size_message() == 1)
	// {
	// 	std::vector<std::string>	vect = cmd->get_message();
	// 	std::cout << "message -> " << vect[0] << std::endl;
	// }
	std::cout << cmd->getClientSfd() << std::endl;
	// close(cmd->get_client_fd());
}
