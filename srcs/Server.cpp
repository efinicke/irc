/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:15:43 by grannou           #+#    #+#             */
/*   Updated: 2023/01/15 20:26:40 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

// Default Constructor
Server::Server(void):_port("6667"), _password(SERVER_PASSWORD), _fd(-1), _message(""), _time(std::time(NULL))
{
    std::cout << GREEN "Default Constructor " RESET "of Class " GREEN "Server " RESET "called" << std::endl;
}

// Constructor with parameters
Server::Server(std::string port, std::string password): _port(port), _password(password), _fd(-1), _message(""), _time(std::time(NULL))
{
    std::cout << GREEN "Constructor " RESET "of Class " GREEN "Server " RESET "called" << std::endl;  
}

// Copy Constructor
Server &Server::operator=(Server const &rhs)
{
    std::cout << YELLOW "Copy Assignment Operator called" RESET << std::endl;
    
    if (this != &rhs)
    {
        this->_port = rhs.getPort();
        this->_password = rhs.getPassword();
        this->_fd = rhs.getFd();
        this->_message = rhs.getMessage();
        this->_time = rhs.getTime();
    }
    return (*this);
}

// Destructor
Server::~Server()
{
    std::cout << RED "Default Destructor " RESET "of Class " RED "Server " RESET "on port " << RED << _port << RESET << " is detroyed" << std::endl;
}

// Accessor/Getter Member Functions
std::string Server::getPort(void) const
{
    return (this->_port);
}

std::string Server::getPassword(void) const
{
    return (this->_password);
}

int Server::getFd(void) const
{
    return (this->_fd);
}

std::string Server::getMessage(void) const
{
    return (this->_message);
}

std::time_t Server::getTime(void) const
{
    return (this->_time);
}

// Setter Member Functions
void    Server::setPort(std::string port)
{
    this->_port = port;
}

void    Server::setPassword(std::string password)
{
    this->_password = password;
}

void    Server::setFd(int fd)
{
    this->_fd = fd;
}

void    Server::setMessage(std::string message)
{
    this->_message = message;
}

void    Server::setTime(std::time_t time)
{
    this->_time = time;
}

// Operator << Overload
std::ostream    &operator<<(std::ostream &out, Server const &server)
{ 
    out << CYAN "Server Infos: \n" 
        << MAGENTA << "Port     = " << RESET << server.getPort() << "\n" 
        << MAGENTA << "Password = " << RESET << server.getPassword() << "\n"
        << MAGENTA << "Fd       = " << RESET << server.getFd() << "\n"
        << MAGENTA << "Message  = " << RESET << server.getMessage() << "\n"
        << MAGENTA << "Time     = " << RESET << server.getTime() << "\n";
    return (out);
}
