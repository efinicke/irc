/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:49:51 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/27 01:04:02 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"
#include "../../includes/Parsing.hpp"

void	check_command(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	if (vect.front() == "INVITE")
		invite_pars(vect, ircServ, client_fd);
	else if (vect.front() == "JOIN")
		join_pars(buffer, vect, ircServ, client_fd);
	else if (vect.front() == "KICK")
		kick_pars(buffer, vect, ircServ, client_fd);
	else if (vect.front() == "KILL")
		kill_pars(buffer, vect, ircServ, client_fd);
	else if (vect.front() == "LIST")
		list_pars(vect, ircServ, client_fd);
	else if (vect.front() == "MOTD")
		motd_pars(vect, ircServ, client_fd);
	else if (vect.front() == "NAMES")
		names_pars(vect, ircServ, client_fd);
	else if (vect.front() == "NICK")
		nick_pars(vect, ircServ, client_fd);
	else if (vect.front() == "NOTICE")
		notice_pars(buffer, vect, ircServ, client_fd);
	else if (vect.front() == "OPER")
		oper_pars(vect, ircServ, client_fd);
	else if (vect.front() == "PART")
		part_pars(vect, ircServ, client_fd);
	else if (vect.front() == "PASS")
		pass_pars(vect, ircServ, client_fd);
	else if (vect.front() == "PING")
		ping_pars(vect, ircServ, client_fd);
	else if (vect.front() == "PRIVMSG")
		privmsg_pars(buffer, vect, ircServ, client_fd);
	else if (vect.front() == "QUIT")
		quit_pars(buffer, vect, ircServ, client_fd);
	else if (vect.front() == "TOPIC")
		topic_pars(buffer, vect, ircServ, client_fd);
	else if (vect.front() == "USER")
		user_pars(buffer, vect, ircServ, client_fd);
	else
	{
		std::string	error = vect.front();
		error += " :Unknown command\r\n";
		int size = error.size();
		send(client_fd, error.c_str(), size, 0);
	}
}

void	parsing(char *buffer, Server *ircServ, int client_fd)
{
	(void)ircServ;

	if (buffer[0] == '\r' && buffer[1] == '\n')
		return ;
	std::vector<std::string> vect;
	std::string	trim = buffer;
	std::istringstream iss(trim);
	std::string token;

	while (std::getline(iss, token, ' '))
	{
		trim = token;
		trim.erase(trim.find_last_not_of("\r\n")+1);
		if (trim != "")
			vect.push_back(trim);
	}
	// print_vector(vect);

	if (vect.size() == 0)
		return ;
	check_command(buffer, vect, ircServ, client_fd);

}
