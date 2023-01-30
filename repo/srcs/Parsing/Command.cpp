/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:42:51 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/27 01:05:52 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

command::command() {}

command::~command() {}

command::command(command const &src)
{
	*this = src;
	return ;
}

///////////////////////////////////////////////
//	ADD
///////////////////////////////////////////////

void	command::add_channels(std::string channel)
{
	this->channels.push_back(channel);
}

void	command::add_nick(std::string nick)
{
	this->nick.push_back(nick);
}

void	command::add_server(std::string server)
{
	this->server.push_back(server);
}

void	command::add_message(std::string test_message)
{
	this->message.push_back(test_message);
}

void	command::add_client_fd(int client_fd)
{
	this->client_fd = client_fd;
}

////////////////////////////////////////////
//	PRINT
////////////////////////////////////////////

void	command::print_channels()
{
	std::vector<std::string>::iterator	it = channels.begin();
	std::vector<std::string>::iterator	ite = channels.end();

	std::cout << MAGENTA << "CHANNELS:" << RESET << std::endl;

	while (it != ite)
	{
		std::cout << "[" << *it << "]" << std::endl;
		it++;
	}
}

void	command::print_nick()
{
	size_t	i = 0;

	std::cout << MAGENTA << "NICK:" << RESET << std::endl;
	while (i < this->nick.size())
	{
		std::cout << "[" << nick[i] << "]" << std::endl;
		i++;
	}
}

void	command::print_server()
{
	size_t	i = 0;

	std::cout << MAGENTA << "SERVER:" << RESET << std::endl;
	while (i < this->server.size())
	{
		std::cout << "[" << server[i] << "]" << std::endl;
		i++;
	}
}

void	command::print_message()
{
	std::vector<std::string>::iterator	it = message.begin();
	std::vector<std::string>::iterator	ite = message.end();

	std::cout << MAGENTA << "MESSAGE:" << RESET << std::endl;

	while (it != ite)
	{
		std::cout << "[" << *it << "]" << std::endl;
		it++;
	}
}

void	command::print_all()
{
	std::cout << std::endl << CYAN << "NEW COMMAND" << RESET << std::endl;
	print_channels();
	print_nick();
	print_server();
	print_message();
}

////////////////////////////////////////
//	GET SIZE
////////////////////////////////////////

int	command::get_size_channels()
{
	return (this->channels.size());
}

int	command::get_size_nick()
{
	return (this->nick.size());
}

int	command::get_size_server()
{
	return (this->server.size());
}

int	command::get_size_message()
{
	return (this->message.size());
}

//////////////////////////////////////////
//	GET VECTOR
//////////////////////////////////////////

std::vector<std::string>	command::getchannels()
{
	return (this->channels);
}

std::vector<std::string>	command::getnickname()
{
	return (this->nick);
}

std::vector<std::string>	command::getserver()
{
	return (this->server);
}

std::vector<std::string>	command::getmessage()
{
	return (this->message);
}

int	command::getClientSfd()
{
	return (this->client_fd);
}
