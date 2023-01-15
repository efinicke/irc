#include "includes/Server.hpp"

static void     printErrorMessage(std::string msg)
{
    std::cerr << KYU BIE << msg << BIE KYU << std::endl;
}

static bool     isInteger(const char *str)
{
    char        *end;
    strtol(str, &end, 10);
    if (*end != '\0' || end == str)
        return (false);
    return (true);
}

int     createSocket(int *socket_fd)
{
    // Create a socket
    *socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (*socket_fd < 0)
        return(printErrorMessage(CREATE_SOCKET_ERROR) ,1);
    std::cout << GREEN << "Creating socket succeed" << RESET << std::endl;
    std::cout << CYAN << "Socket fd = " << RESET << *socket_fd << std::endl;

    // Set the socket to non-blocking
    int flags = fcntl(*socket_fd, F_GETFL, 0);
    fcntl(*socket_fd, F_SETFL, flags | O_NONBLOCK);

    return (0);
}

int     bindSocket(int *socket_fd)
{
    // Binding socket to an IP address and port
    struct sockaddr_in  serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(*socket_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        return (printErrorMessage(BIND_SOCKET_ERROR), 1);
    std::cout << GREEN << "Binding socket succeed" << RESET << std::endl;
    return (0);
}

int     listenSocket(int *socket_fd)
{
    // Listen for incoming connections
    if (listen(*socket_fd, SOCKET_MAX_CONNECTIONS) < 0) // Allow up to SOCKET_MAX connections to queue up
        return (printErrorMessage(LISTEN_SOCKET_ERROR), 1);
    return (0);
}

int     initialiseSocket(int *socket_fd)
{
    if (createSocket(socket_fd) || bindSocket(socket_fd) || listenSocket(socket_fd))
        return (1);
    return (0);
}

/*
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        std::cout << "good" << std::endl;
        Server ircServ(argv[1], argv[2]);
        std::cout << ircServ.getPort() << std::endl;
        std::cout << ircServ.getPassword() << std::endl;
    }
    return (0);
}
*/

static int     checkArguments(int argc, char **argv)
{
    try
    {
        if (argc != 3)
        {
            throw std::runtime_error(KYU BIE ARGS_ERROR PROGRAM_LAUNCH1 PROGRAM_LAUNCH2 BIE KYU);
        }
        if (!isInteger(argv[1]))
        {
            throw std::runtime_error(KYU BIE PORT_DIGIT_ERROR BIE KYU);
        }
        long int argv1 = std::atoll(argv[1]);
        if (argv1 <= 0 || argv1 > PORT_MAX)
        {
            throw std::runtime_error(KYU BIE PORT_RANGE_ERROR BIE KYU);
        }
        std::string argv2(argv[2]);
        if (argv2.length() > SERVER_PASSWORD_LENGTH)
        {
            throw std::runtime_error(KYU BIE PASSWORD_ERROR BIE KYU);
        }
        if (argv1 != SERVER_PORT || argv2 != SERVER_PASSWORD)
        {
            throw std::runtime_error(KYU BIE VALID_ARGS_ERROR BIE KYU);
        }
        std::cout << KYU BIE VALID_INPUT BIE KYU << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    //std::cout << CLEARLINE;
    int server_socket_fd;

    if (checkArguments(argc, argv))
        return (1);

    if (initialiseSocket(&server_socket_fd))
    {
        std::cerr << "Initialising socket failed" << std::endl;
        printErrorMessage(INITIALISE_SOCKET_ERROR);
        return (1);
    }
    
    // Keep track of all client sockets
    std::vector<int> clients;
    Server  ircServ = Server(argv[1], argv[2]);

    // Set server socket to Server class
    ircServ.setFd(server_socket_fd);

    // Print Server infos
    std::cout << ircServ << std::endl;

    int epoll_fd = epoll_create1(0);

    struct epoll_event event;
    struct epoll_event* events;
    events = (struct epoll_event*) calloc(MAX_EVENTS, sizeof(struct epoll_event));
    event.data.fd = ircServ.getFd();
    event.events = EPOLLIN;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, ircServ.getFd(), &event);
    while (TRUE)
    {
        int n = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        for (int i = 0; i < n; i++) {
            if ((events[i].events & EPOLLERR) || (events[i].events & EPOLLHUP) || (!(events[i].events & EPOLLIN)))
            {
                close(events[i].data.fd);
                continue;
            }
            else if (ircServ.getFd() == events[i].data.fd)
            {
                int client_fd = accept(ircServ.getFd(), NULL, NULL);
                event.data.fd = client_fd;
                event.events = EPOLLIN;
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &event);
            }
            else
            {
                int client_fd = events[i].data.fd;
                char buffer[1024];
                int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
                if (bytes_received <= 0)
                {
                    close(client_fd);
                }
                else
                {
                    buffer[bytes_received] = '\0';
                    std::cout << GREEN << "Message from client: " << RESET << buffer << std::endl;
                    if (strcmp(buffer, "/quit") == 0)
                    {
                        close(client_fd);
                        break;
                    }
                }
            }
        }
    }

    std::cout << RED << "Closing socket" RESET << std::endl;
    close(ircServ.getFd());

    return (0);
}