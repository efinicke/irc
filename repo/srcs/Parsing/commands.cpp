/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 06:24:42 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/27 00:58:17 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Parsing.hpp"

void	invite_pars(std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)ircServ;
	command	*cmd = new command();

	if (vect.size() != 3)
		std::cout << "error: wrong number of arguments" << std::endl;
	if (vect.size() < 3)
	{
		std::string err = "Invite :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else if (check_channel(2, vect) == 1)
		std::cout << "error: channel: wrong syntaxe" << std::endl;
	else
	{
		cmd->add_nick(vect[1]);
		cmd->add_channels(vect[2]);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
	}
	delete cmd;
}

void	join_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)buffer;
	(void)ircServ;
	std::string	message;
	command	*cmd = new command();
	
	if (vect.size() < 2)
	{
		std::string err = "Join :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else if (check_channel(1, vect) == 1)
		std::cout << "Error: channel: wrong syntaxe" << std::endl;
	else 
	{
		if (vect.size() > 2)
		{
			message = join_message(buffer, 2, vect);
			cmd->add_message(message);
		}
		cmd->add_channels(vect[1]);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
	}
	delete cmd;
}

void	kick_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)buffer;
	(void)ircServ;
	command	*cmd = new command();
	
	if (vect.size() < 3)
	{
		std::string err = "Kick :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else if (check_channel(1, vect) == 1)
		std::cout << "Error: channel: wrong syntaxe" << std::endl;
	else 
	{
		if (vect.size() > 3)
		{
			std::string message = join_message(buffer, 3, vect);
			cmd->add_message(message);
		}
		cmd->add_channels(vect[1]);
		cmd->add_nick(vect[2]);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
	}
	delete cmd;
}

void	kill_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)buffer;
	(void)ircServ;
	command	*cmd = new command();

	if (vect.size() < 2)
	{
		std::string err = "Kill :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else
	{
		if (vect.size() > 2)
		{
			std::string message = join_message(buffer, 2, vect);
			cmd->add_message(message);
		}
		cmd->add_nick(vect[1]);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
	}
	delete cmd;
}


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
void	list_pars(std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)ircServ;
	(void)client_fd;

	if (vect.size() > 6)
		std::cout << "error: wrong number of arguments" << std::endl;
	else if (vect.size() == 2)
		std::cout << RED << ">>>>>> PARSING PAS FINI <<<<<<" << RESET << std::endl;
	else
		std::cout << "OK :)" << std::endl;


		////////////////////////////////////////////////////////
		//					ON VERRA PLUS TARD
		////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

void	motd_pars(std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)ircServ;
	command	*cmd = new command();

	if (vect.size() != 1 && vect.size() != 2)
		std::cout << "error: wrong number of arguments" << std::endl;
	else
	{
		if (vect.size() == 2)
			cmd->add_server(vect[1]);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
	}
	delete cmd;
}

void	names_pars(std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)ircServ;
	command	*cmd = new command();

	if (vect.size() != 1 && vect.size() != 2)
		std::cout << "error: wrong number of arguments" << std::endl;
	else if (vect.size() == 2 && check_channel(1, vect) == 1)
		std::cout << "Error: channel: wrong syntaxe" << std::endl;
	else
	{
		if (vect.size() == 2)
			cmd->add_channels(vect[1]);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
	}
	delete cmd;
}

void	nick_pars(std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)ircServ;
	command	*cmd = new command();

	
	if (vect.size() < 2)
	{
		std::string err = "Nick :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else if (vect.size() != 2)
		std::cout << "error: wrong number of arguments" << std::endl;
	else
	{
		cmd->add_nick(vect[1]);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
	}
	delete cmd;
}

void	notice_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)buffer;
	(void)ircServ;
	command	*cmd = new command();

	if (vect.size() < 3)
	{
		std::string err = "Notice :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else
	{
		std::string message = join_message(buffer, 2, vect);
		if (vect[1][0] == '#')
			cmd->add_channels(vect[1]);
		else
			cmd->add_nick(vect[1]);
		cmd->add_message(message);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
	}
	delete cmd;
}

void	oper_pars(std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)ircServ;
	command	*cmd = new command();

	if (vect.size() < 3)
	{
		std::string err = "Oper :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else if (vect.size() != 3)
		std::cout << "error: wrong number of arguments" << std::endl;
	else
	{
		cmd->add_nick(vect[1]);
		cmd->add_message(vect[2]);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
	}
	delete cmd;
}

void	part_pars(std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)ircServ;
	command	*cmd = new command();


	if (vect.size() < 3)
	{
		std::string err = "Part :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else if (vect.size() != 2)
	{
		std::cout << "error: wrong number of arguments" << std::endl;
		return;
	}

	std::string channels = vect[1];
	std::istringstream iss(channels);
	std::string token;

	while (std::getline(iss, token, ','))
	{
		channels = token;
		if (channels[0] != '#')
		{
			std::cout << "Error: channel: wrong syntaxe" << std::endl;
			return ;
		}
		cmd->add_channels(channels);
	}
	cmd->add_client_fd(client_fd);
	cmd->print_all();
	delete cmd;
}

void	pass_pars(std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)ircServ;
	command	*cmd = new command();

	
	if (vect.size() < 2)
	{
		std::string err = "Pass :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else if (vect.size() != 2)
		std::cout << "error: wrong number of arguments" << std::endl;
	else
	{
		cmd->add_message(vect[1]);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
		pass_cmd(cmd, ircServ);
	}
	delete cmd;
}

void	ping_pars(std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)ircServ;
	command	*cmd = new command();

	if (vect.size() < 2)
	{
		std::string err = "Ping :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else if (vect.size() != 2)
		std::cout << "error: wrong number of arguments" << std::endl;
	else
	{
		if (vect[1][0] == '#')
			cmd->add_channels(vect[1]);
		else
			cmd->add_nick(vect[1]);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
	}
	delete cmd;
}

void	privmsg_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)buffer;
	(void)ircServ;
	command	*cmd = new command();

	if (vect.size() < 3)
	{
		std::string err = "Privmsg :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else
	{
		std::string message = join_message(buffer, 2, vect);
		if (vect[1][0] == '#')
			cmd->add_channels(vect[1]);
		else
			cmd->add_nick(vect[1]);
		cmd->add_message(message);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
	}
	delete cmd;
}

void	quit_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)buffer;
	(void)ircServ;
	(void)vect;
	command	*cmd = new command();

	if (vect.size() > 1)
	{
		std::string message = join_message(buffer, 1, vect);
		cmd->add_message(message);
	}
	cmd->add_client_fd(client_fd);
	cmd->print_all();
	quit_cmd(cmd, ircServ);
	delete cmd;
}

void	topic_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)buffer;
	(void)ircServ;
	command	*cmd = new command();
	
	if (vect.size() < 2)
	{
		std::string err = "Topic :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else if (check_channel(1, vect) == 1)
		std::cout << "Error: channel: wrong syntaxe" << std::endl;
	else
	{
		if (vect.size() > 2)
		{
			std::string message = join_message(buffer, 2, vect);
			cmd->add_message(message);
		}
		cmd->add_channels(vect[1]);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
	}
	delete cmd;
}

// void	user_pars(std::vector<std::string> vect, Server *ircServ, int client_fd)
// {
// 	(void)ircServ;
// 	command	*cmd = new command();

// 	if (vect.size() != 1 && vect.size() != 2)
// 		std::cout << "error: wrong number of arguments" << std::endl;
// 	else
// 	{
// 		if (vect.size() > 1)
// 			cmd->add_server(vect[1]);
// 		cmd->add_client_fd(client_fd);
// 		cmd->print_all();
// 	}
// 	delete cmd;
// }

void	user_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd)
{
	(void)ircServ;
	command	*cmd = new command();

	if (vect.size() < 5)
	{
		std::string err = "User :Not enough parameters given\r\n";
		send(client_fd, err.c_str(), err.size(), 0);
	}
	else
	{
		std::string message = join_message(buffer, 4, vect);
		cmd->add_message(message);
		cmd->add_server(vect[3]);
		cmd->add_nick(vect[1]);
		cmd->add_client_fd(client_fd);
		cmd->print_all();
		user_cmd(vect[2], "nickname", cmd, ircServ);
	}
	delete cmd;
}

// nickname - name which appears for other users
// username - name you use to login, allows system to identify you
// password - sequence of symbols, which allows system to match you with your username
// real name - this is just additional information about you
