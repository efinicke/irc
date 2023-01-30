/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grannou <grannou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:15:43 by grannou           #+#    #+#             */
/*   Updated: 2023/01/29 11:50:36 by grannou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"
#include "../includes/Parsing.hpp"

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
Server::Server(Server const &rhs)
{
	*this = rhs;
	return ;
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
    std::cout << RED "Default Destructor " RESET "of Class " RED "Server " RESET "on port " << RED << _port << RESET << " is destroyed" << std::endl;
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

std::vector<Channel> Server::getIRCChannels() const
{
    return (this->_channels);
}

std::map<int, User>  Server::getIRCUsers() const
{
    return (this->_users);
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

// Set up Server
int     Server::setup()
{
    int     optionValue = 1;
    
    // Create a socket
    if ((_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return (printErrorMessage(CREATE_SOCKET_ERROR), 1);
    std::cout << GREEN << "Creating socket succeed" << RESET << std::endl;
    std::cout << CYAN << "Server Socket fd = " << RESET << _fd << std::endl;

    // Set socket options    
	if (setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &optionValue, sizeof(optionValue)) < 0)
        return (printErrorMessage(SET_SOCKET_OPTION_ERROR), 1);

    // Set the socket to non-blocking
	if (fcntl(_fd, F_SETFL, O_NONBLOCK) < 0)
		return (printErrorMessage(NON_BLOCKING_SOCKET_ERROR), 1);
    std::cout << GREEN << "Setting non blocking socket succeed" << RESET << std::endl;
    
    // Binding socket to an IP address and port
    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = INADDR_ANY;
    _address.sin_port = htons(SERVER_PORT);

    if (bind(_fd, (struct sockaddr*)&_address, sizeof(_address)) < 0)
        return (printErrorMessage(BIND_SOCKET_ERROR), 1);
    std::cout << GREEN << "Binding socket succeed" << RESET << std::endl;

    // Listen for incoming connections
    if (listen(_fd, SOCKET_MAX_CONNECTIONS) < 0) 
    return (printErrorMessage(LISTEN_SOCKET_ERROR), 1);

    return (0);
}


// Launch and run Server
int    Server::run()
{
    // Keep track of all client sockets
    std::vector<int> clients;

    // Create a event descriptor epoll
    int epoll_fd = epoll_create1(0);
    if (epoll_fd < 0)
        return (printErrorMessage(KYU BIE CREATE_EPOLL_FD_ERROR BIE KYU), 1);

    // Add the server socket to the event descriptor epoll
    struct epoll_event event;
    event.data.fd = _fd;
    event.events = EPOLLIN | EPOLLET;

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, _fd, &event) < 0)
        return (printErrorMessage(ADDING_SERVER_FD_EPOLL_ERROR), 1);


    // Events loop
    while (true)
    {
        struct epoll_event  events[MAX_EVENTS];
        
        int eventsNumber = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (eventsNumber == -1)
        {
            printErrorMessage(WAITING_EPOLL_ERROR);
            break;
        }
        
        for (int i = 0; i < eventsNumber; i++)
        {
            // Error handling
            if ((events[i].events & EPOLLERR) || (events[i].events & EPOLLHUP) || (!(events[i].events & EPOLLIN)))
            {
                printErrorMessage(EPOLL_FD_ERROR);
                close(events[i].data.fd);
                continue;
            }
            // New incoming connection
            else if (events[i].data.fd == _fd)
            {

                struct sockaddr_in      clientAddress;
                socklen_t               clientAddressSize = sizeof(clientAddress);
                
                int clientFd = accept(_fd, (struct sockaddr *)&clientAddress, &clientAddressSize);
                if (clientFd == -1)
                {
                    if ((errno == EAGAIN) || (errno == EWOULDBLOCK))
                        break;
                    else
                    {
                        printErrorMessage(ACCEPTING_CONNECTION_ERROR);
                        break;
                    }
                    continue;
                }
                
                // Add the new client to the epoll event file descriptor
                event.data.fd = clientFd;
                event.events = EPOLLIN;
                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, clientFd, &event) == -1)
                {
                    printErrorMessage(ADDING_CLIENT_FD_EPOLL_ERROR);
                    continue;
                }
            }

            // Data from a client    
            else 
            {
                int clientFd = events[i].data.fd;
                std::vector<char>   buffer(1024);
                int bytesReceived = read(clientFd, buffer.data(), buffer.size());
                if (bytesReceived == -1)
                {
                    printErrorMessage(READING_CLIENT_DATA_ERROR);
                    continue;
                }
                if (bytesReceived == 0)
                {
                    // Disconnect client
                    if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, clientFd, &event) == -1)
                        printErrorMessage(READING_CLIENT_DATA_ERROR);
                    std::cout << GREEN << "Closing connection of file descriptor " << RESET << clientFd << std::endl; 
                    close(clientFd);
                    continue;
                }
                
//                buffer[bytesReceived] = '\0';
                std::cout << GREEN << "Message from client: " << RESET << std::string(buffer.data(), bytesReceived) << std::endl;

                // Echo the message back to the clieny              
                int bytesSent = write(clientFd, buffer.data(), bytesReceived);
                if (bytesSent == -1)
                    printErrorMessage(WRITING_CLIENT_DATA_ERROR);

                // Parsing command later
                //////////////////////////
                //        PARSING       //
                //////////////////////////
                parsing(buffer.data(), this, clientFd);
                //////////////////////////
            }
        }
    }

    std::cout << RED << "Closing socket" RESET << std::endl;
    close(_fd);
    return (0);
}

// Ajouter un utilisateur: 
void                 Server::addIRCUser(int sfd, std::string username, std::string nickname, std::string hostname, std::string realname, char userModes)
{
    User user = User(sfd, username, nickname, hostname, realname, userModes);
    this->_users.insert(std::make_pair(sfd, user));
}

void                 Server::addIRCUser(int sfd, std::string username, std::string nickname, std::string hostname, std::string realname)
{
    User user = User(sfd, username, nickname, hostname, realname);
    this->_users.insert(std::make_pair(sfd, user));
}

void	Server::add_user(std::string nickname, std::string username, std::string hostname, std::string servername, std::string realname, int client_fd)
{
	User	user(nickname, username, hostname, servername, realname);
	this->_users.insert(std::make_pair(client_fd, user));
	// std::map<int, User>::iterator	it = _users.begin();
	// std::map<int, User>::iterator	ite = _users.end();

	// while (it != ite)
	// {
	// 	std::cout << "	" << it->first << "	|	" << it->second << std::endl;
	// 	it++;
	// }

}

void                 Server::removeUser(int sfd){
    this->_users.erase(this->_users.find(sfd));
}

// Ajouter un channel:

void                 Server::addIRCChannel(std::string name)
{
    Channel channel = Channel(name);
	this->_channels.push_back(channel);
}

void                 Server::addIRCChannel(std::string name, char setModes)
{
    Channel channel = Channel(name, setModes);
	this->_channels.push_back(channel);
}

void                 Server::addIRCChannel(std::string name, std::string password)
{
    Channel channel = Channel(name, password);
	this->_channels.push_back(channel);
}

void                 Server::addIRCChannel(std::string name, std::string password, char setModes)
{
    Channel channel = Channel(name, password, setModes);
	this->_channels.push_back(channel);
}

void                 Server::removeIRCChannel(std::string name){
    
    std::vector<Channel>::iterator it = this->_channels.begin();

    for ( ; it != this->_channels.end(); it++){
    	if (it->getName() == name)
            this->_channels.erase(it);
    }
}

// Envoyer un message a un client: 
int                  Server::sendMsg(std::string msg, int fd)
{
    return (send(fd, msg.c_str(), msg.length(), MSG_CONFIRM));
}

// Retrouver un User ou savoir s'il existe à partir de son nickname:
User    *Server::findUser(std::string nickname)
{
    std::map<int, User>::iterator it;
     
    for (it = this->_users.begin();it != this->_users.end(); it++)
    {
    	if (it->second.getNickname() == nickname)
            return (&it->second);
    }
    return (&it->second);    
}

// Retrouver un Channel ou savoir s'il existe à partir de son nom:
Channel				 *Server::findChannel(std::string name)
{
    std::vector<Channel>::iterator it;
    int     index = 0;
     
    for (it = this->_channels.begin(); it != this->_channels.end(); it++)
    {
    	if (it->getName() == name)
        {
            index = it - this->_channels.begin();
            return (&(this->_channels[index]));
        }
    }
    return (NULL);    
}

// Rechercher un User dans une map ou savoir s'il existe à partir de sa clé (socket file descriptor):
User        		 *Server::findUser(int fd)
{
    std::map<int, User>::iterator it = this->_users.find(fd);
    if (it != this->_users.end())
        return (&it->second);
    return (NULL);
}



// void	Cmd::print(void)
// {
// 	std::vector<std::string>::iterator it = _value.begin();

// 	while (it != _value.end())
// 	{
// 		std::cout << it->data() << std::endl;
// 		it++;
// 	}
// 	if (_user)
// 		_user->print();
// 	else
// 	 	std::cout << "no user" << std::endl;
// 	std::cout << "end of Cmd.print()" << std::endl;
// }


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
