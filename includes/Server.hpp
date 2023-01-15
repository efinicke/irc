/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 07:19:13 by grannou           #+#    #+#             */
/*   Updated: 2023/01/15 19:26:38 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP

# define SERVER_HPP

# include <unistd.h>
# include <iostream>
# include <cstdio>
# include <sstream>
# include <cctype>
# include <sys/socket.h>
# include <sys/epoll.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <string>
# include <cstring>
# include <string.h>
# include <locale>
# include <unistd.h>
# include <cstdlib>
# include <errno.h>
# include <vector>
# include <algorithm>
# include <map>

# include "Channel.hpp"
# include "User.hpp"

// #pragma once is a preprocessor directive used to prevent header files 
// from being included multiple times. 
// The #pragma once directive, once present in a file, assures that the file 
// will not be included multiple times in the current project.
#pragma once

// Terminal color display
# define BLACK          "\033[30m"
# define RED            "\033[31m"
# define GREEN          "\033[32m"
# define YELLOW         "\033[33m"
# define BLUE           "\033[34m"
# define MAGENTA        "\033[35m"
# define CYAN           "\033[36m"
# define WHITE          "\033[37m"
# define RESET          "\033[0m"

# define KYU "🔮🦋🧡🍁🐞🍄🍀🌇🌸🐹🌳🦊🐼🌿🧡🦊🧡🌿🐼🦊🌳🐹🌸🌇🍀🍄🐞🍁🧡🦋🔮\n"
# define BIE "🍀🌸🦊                                                  🦊🌸🍀\n"
# define ARGS_ERROR "🎑🌸🦊         " YELLOW "ERROR" RESET " : wrong number of arguments        🦊🌸🎑\n"
# define PROGRAM_LAUNCH1 "🎑🌸🦊         " GREEN "Launch" RESET " ./ircserv <port> <password>       🦊🌸🎑\n"
# define PROGRAM_LAUNCH2 "🎑🌸🦊        " GREEN "or make run" RESET " (./ircserv 6667 password)     🦊🌸🎑\n"
# define PORT_DIGIT_ERROR "🎑🌸🦊       " YELLOW "ERROR" RESET " : port number is not a number        🦊🌸🎑\n"
# define PORT_RANGE_ERROR "🎑🌸🦊       " YELLOW "ERROR" RESET " : port number is out of range        🦊🌸🎑\n"
# define PASSWORD_ERROR "🎑🌸🦊           " YELLOW "ERROR" RESET " : password is too long           🦊🌸🎑\n"
# define VALID_ARGS_ERROR "🎑🌸🦊      " YELLOW "ERROR" RESET " : port and/or password invalid        🦊🌸🎑\n"
# define VALID_INPUT "🎑🌸🦊                   " GREEN "VALID INPUT" RESET "                    🦊🌸🎑\n"


# define CREATE_SOCKET_ERROR "🎑🌸🦊         " YELLOW "ERROR" RESET " : creating socket faiiled          🦊🌸🎑\n"
# define BIND_SOCKET_ERROR "🎑🌸🦊          " YELLOW "ERROR" RESET " : binding socket failed           🦊🌸🎑\n"
# define LISTEN_SOCKET_ERROR "🎑🌸🦊       " YELLOW "ERROR" RESET " : listening on socket failed         🦊🌸🎑\n"
# define INITIALISE_SOCKET_ERROR "🎑🌸🦊       " YELLOW "ERROR" RESET " : Initialising socket failed         🦊🌸🎑\n"


// Clear terminal display
# define CLEARLINE "\033[2J\033[1;1H"

# define SERVER_PORT 6667
# define SERVER_PASSWORD "password"
# define SERVER_PASSWORD_LENGTH 12
# define TRUE   1
# define FALSE  0
# define PORT_MAX 65535
# define SOCKET_MAX_CONNECTIONS 10
# define MAX_EVENTS 64

/* OCCF, Orthodox Canonical Class Form:

    class A final
    {
        public:
            A ();
            A (const A &a);
            ~A ();
            A & operator = (const A &a);
    };  
    rhs = right hand side (opposite to left hand side = this)
*/

// Prototypes of other classes
/*
Class User;
Class Channel;
Class Command;
*/

class Server
{
    public:

        // Default Constructor
        Server(void);

        // Constructor with parameter
        Server(std::string port, std::string password);

        // Copy Constructor
        Server (Server const &source);

        // Copy Assignment
        Server &operator=(Server const &rhs);

        // Destructor
        ~Server();

        // Getter Member Functions
        std::string         getPort() const;
        std::string         getPassword() const;
        int                 getFd() const;
        std::string         getMessage() const;
        std::time_t         getTime() const;

        // Setter Member Functions
        void                setPort(std::string port);
        void                setPassword(std::string password);
        void                setFd(int fd);
        void                setMessage(std::string message);
        void                setTime(std::time_t time);

        protected:

        private:

            std::string     _port;
            std::string     _password;
            int             _fd;
            std::string     _message;
            std::time_t     _time;

            // LISTE DE TOUS LES CHANNELS DU SERVER
            std::vector<Channel>	_channels;
            // LISTE DE TOUS LES USERS DU SERVER (associes a leur socket)
            std::map<int, User>		_usersList;

};

// Operator << overload
std::ostream    &operator<<(std::ostream &out, Server const &server);

#endif
