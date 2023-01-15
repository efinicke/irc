IRC tutorial

NOTE: test en make run puis dans un autre terminal nc -C localhost 6667 (-C permet de mettre automatiquement \r\n)
    OU make run et dans un autre terminal irssi puis /connect localhost 6667
    pour le parsing look at strok() ou strtok()
    look les fonctions de string

Onglets Google Grannou
https://medium.com/from-the-scratch/http-server-what-do-you-need-to-know-to-build-a-simple-http-server-from-scratch-d1ef8945e4fa
https://ircgod.com/posts/ircserver1/building-an-irc-server-1/
https://www.ibm.com/docs/en/i/7.3?topic=designs-example-nonblocking-io-select
https://github.com/execrate0/ft_irc
https://datatracker.ietf.org/doc/html/rfc2812
https://fr.wikipedia.org/wiki/Internet_Relay_Chat
https://www.youtube.com/watch?v=9J1nJOivdyw
https://www.youtube.com/watch?v=xfRdYrQUQeQ
http://sdz.tdct.org/sdz/les-sockets.html
https://oramind.com/tutorial-how-to-make-an-irc-server-connection/
https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-recv
https://github.com/vivimbob/ft_irc/blob/main/srcs/ft_ircd.cpp
astrid42-code
https://openai.com/blog/chatgpt/

###################
REPARTITION TRAVAIL
###################

    ##################
    PARTIE 1 - Serveur
    ##################

        Creer un serveur qui compile
            creer la socket, la bind, listen et accept
        Le close avec un signal (cf Minitalk signal/sigaction structure)
        Tester la connexion avec Netcat (deja installe sur la session) puis irssi
        *Pleurer*
        Attention: poll() ne fonctionne pas sur mac
        Checkpoint: qd j;envoie un message via irssi, le serveur repond bien recu et/ou le message recu
        Pour se remettre dans le bain de C++, faire le sujet de exam05 avec une map
        L'exam06 est coder un serveur qui recoit des requetes
        Creer une classe Client
        Coder les fonction primaires pour le client (commandes client):
            pass()
            user()
            nick()
            quit() (le client s'en va)
        Gerer les deux sens nick-user et user-nick
        *Pleurer*
        Gerer les reply de base et commnandes de base
        Tout ERR et RPL finit par \r\n
        *Le vrai taf commence*
        *Pleurer*
        Implementer poll(), la gestion de plusieurs clients
        Ranger les clients dans une map (aller voir Lara)
        Check les erreurs (pas de doublons user/nickname, password)
        Optionnel:
            coder ping() et pong() eet gettime()
            si irssi envoit a serveur ping(argv1) alors serveur doit repondre pong(argv1 de ping)
            Prevoir un delai d'attente de pong assez long (env 3 minutes)
            Ca sert a verifier si un user est encore actif (ex: riri, fifi et loulou sont actifs sur le serveur, riri ping loulou, l'ordi de loulou a   plante, loulou est considere inactif apres le delai sil ne pong pas, il est delete) 

    ##############################################################
    PARTIE 2 - Toutes les commandes ne concernant pas les channels
    ##############################################################

        Pour se remettre au C++, s'entrainer sur l'exam05 avec une map
        Creer une classe Client
        oper() cree un serveur operateur (admin, mode -o)
        nick() et user() si pas fait en partie 1
        privmsg() et notice() qui ont la meme fonction
            le 2eme argument de privmsg precise si la destination est une conversation privee ou un channel (partie 3)
        *Pleurer*
        Tester avec Netcat puis irssi, verifier que le serveur se segfault pas et pas de leaks
        *Pleurer*
        irssi recup automatiquement les infos 
            ex: username = grannou
            hostname = e1r1p1, obtenu avec gethostname()
            fullname = grannou@e1r1p1

    #######################################################
    PARTIE 3 - Toutes les commandes concernant les channels
    #######################################################

        Creer une class Channel
        Ne pas oublier de free tous les channels soit quand:
            - il n'y a plus de users dans le channel
            - le serveur est close
        join()      creer/rejoindre un channel
        part()      quitter un channel
        gettime()   afficher l'heure de creation du channel/topic
        topic()     ajouter une description du channel
        names()     liste tous les users du channel
        list()      liste tous les channels
        kick()      supprime un user d'un channel
        privmsg() et notice() pour les channels
        *Pleurer*
        quit()      le user doit sortir de tous les channels ou il est et afficher un message dans chacun genre "Goodbye" 
        Tester le fonctionnement des channels avec Netcat puis irssi
        *Pleurer*
        gerer les modes operateur

    ################
    PARTIE 4 - Bonus
    ################

        irssi gere de base l'envoi de fichier, aller regarder le fornmat de la commande
        a voir pour le bot qui est un client qui est une machine et qui repond un message automatique quand on lui ecrit
        Interessant pour avoir plus d'XP et de jours de BH pour Transcendence


#####################
grannou documentation
#####################

Avoir la resolution dynamique sur la VM:
    sudo apt-get install virtualbox-guest-additions-iso

utiliser irssi, client d'irc console
    (sudo apt-get install irssi)
    deja installe sur Dell 
        irssi --version
        irssi 1.2.3-1ubuntu4 (20210409 0011) // irssi 1.2.2-1ubuntu1.1 (20198829 0225 sur VM)

Definition:

    Un serveur web
        1 listens
            attend de recevoir une requete, sinon ne fait rien
        2 on a port
            un OS possede environ 65535 ports donc si on tape son IP, on ne precise pas comment acceder a l'appli serveur
            donc un seul ordi peut avoir plein de serveurs simultanes
        3 for a request
            envoyee par le client pour se connecter au serveur
            un requete se fait par le protocole de transfert hypertext (HTTP)
                exemple de requete simple (juste header sans body):
                    GET /orders.123 HTTP/1.1           (request message target http version)
                    Host: 27.0.0.1:6667                 (IP and port to send the request to)
                    User-Agent: Manual-Http-Request     (type of browser to use)
        4 transport layer
            c'est le protocole de transport des donnees, ici les requetes
            TCP -> Tranmission Control Protocol             
        5 response
             
        6 ressource

Socket Programming Basics Presentation (https://www.youtube.com/watch?v=eVYsIolL2gE)

    Socket programming is useful to build any Networked Application
        WWW (Internet explorer, Firefox...)
        FTP (WS FTP)
        P2P (Limewire, Bitcomet)
    
    Pre-requisites
        Basic of IP/TCP/UDP (Internet Protocol / Tranmission Control Protocol / User Datagram Protocol)
        C/C++ programming basics
        Data structures basics
        Compilation of code on Linux/Unix using gcc
    
    Telephone analogy
        a telephone call over a "telehony network" works as follows:
            both parties have a telephone installed
            a phone number is assigned to each telephone
            turn on ringer to listen for a caller
            caller lifts telephone and dials a number
            telephone rings and the receiver of the call picks it up
            both parties talk and exchange data
            after conversation is over they hang up the phone
    
    Dissecting the analogy
        a network application works as follows:
            an endpoint (telephone) for communication is created on both ends
            an address (phone number) is assigned to both ends to distinguish them from the rest of the network
            one of tne endpoints (caller) initiate a connection to the other
            the other end (receiver) point waits for the communicatiom to start
            once a connection has been made, data is exchanged (talk)
            once data has been exchanged the endpoints are closed up (hang up)

    Sockets Vocabulary
        socket()        = endpoint of communication for sending or receiving data across 
                        a computer network
        bind()          = assign a unique telephone number, assigns a local protocol address to a socket
                        it is used to associate a socket with a specific network interface and port so that the socket
                        can send and receive data on the specified interface and port
        listen()        = wait for a caller, allows a socket to listen for incoming connections
        connect()       = dial a number
        accept()        = receive a call
        send(), recv()  = talk
        close()         = hang up

    The Client - Server model
        Server  = an entity which is a provider of information
        Client  = an entity which is a seeker of information
        example: Apache is a web server providing web pages (information) and Internet Explorer is a web client which requests those pages from the server
        In the socket programming world almost all communication is based on the Client-Server model
        The server starts up first and waits for a client to connect to it. After a client successfully connects, it requests some information. The server serves this information to the client. The client then disconnects and the server waits for more clients. 

    A TCP Server-CLient Interaction

        SERVER
        socket()
            |
        bind()
            |
        listen()
            |                                    CLIENT
        accept()                                
            |                                    socket()
        blocks until connection fron client         |    
            | <---- Connection establishment --- connect()       
            |                                       |
        read() <---- Data (request) ------------ write()
            |                                       |    
        Process request                             | 
            |                                       |
        write() <--- Data (reply) -------------- read() 
            |                                       |
        close()                                  close()

#############################
Functions Prototypes du sujet
#############################

    ############
    # socket() #
    ############
        create a socket

        int socket(int domain, int type, int protocol);
            #include <sys/socket.h>
        domain = specifies the communication domain in which the socket will be used
            AF_INET  -> IPv4presidents
            AF_INET6 -> IPv6
            AF_UNIX  -> local channel, similar to pipes
            AF_ISO   -> ISO protocols
            AF_NS    -> Xerox Network Systems protocols
        type = specifies the type of socket to be created
            SOCK_STREAM -> stream socket, virtual circuit service
            SOCK_DGRAM  -> datagram socket, datagram service
            SOCK_RAW    -> direct IP service
        protocol = specifies the particular protocol to be used with the socket
            0 in general
        returns a file descriptor that can be used to refer to the socket im other function calls. If the function fails, it returns -1
        example:
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    ################
    # setsockopt() #
    ################
        set options for a socket

            #include <sys/socket.h>
            int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
        
        sockfd = socket file descriptor (non-negative integer)
        level = level at which the option resides
        optname = option to be set
        optval = pointer to a buffer containing the value to be set for the option
        optlen = length of the optval buffer
        returns 0 on success, -1 on error (use perror() function to print a message describing the error or std::cerr << 'error message' << std::endl;)
        ex:
            int sockfd, optval;
            optval = 1;
            setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
        options:
            SO_REUSEADDR: allows a socket to bind to a port still in the process of being released
            SO_KEEPALIVE: enables keep-alive packets on a TCP socket that detects inactive connection
                and prevent them from being terminated by a firewall
            SO_LINGER: specify the behavior of a socket when it's closed, will block any further send
                operations until all data is transmitted or set linger time has expired
            SO_RCVTIMEO: specify a time out value for receive operations on a socket
            SO_SNDTIMEO: specify a time out value for send operations on a socket
            full list of options in the sys/socket.h header file

    #################
    # getsockname() #
    #################
        retrieves the locally boind-name of a socket. Typically used with connection-oriented sockets as SOCK_STREAM for TCP, to determine the local address and port to which the socket is bound
        
            #include <sys/socket.h>
            #include <netinet/in.h> (for IPv4)
                + #include <arpa/inet.h> (for IPv6)
            int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
        
        sockfd = socket file descriptor (non-negative integer)
        addr = pointer to a sockaddr structure that contains the address information for the socket
                the type of the structure depends on the address family (here sockadrr_in for IPv4)
        addrlen = size of the address structure in bytes
        returns 0 on success, -1 on error (use perror() function to print a message describing the error or std::cerr << 'error message' << std::endl;)

        struct sockaddr_in
        {
            sa_family_t     sin_family;         // Address family (AF_INET for IPv4)
            uint15_t        sin_port;           // Port number (in network byte order)
            struct in_addr  sin_addr;           // IPv4 address (in network byte order)
            char            sin_zero[8]         // Padding to make structure the same size as sockaddr   
        }
        ex:
            #include <sys/types.h>
            #include <sys/socket.h>
            #include <netinet/in.h>
            #include <arpa/inet.h>

            int sockfd;
            struct sockaddr_in addr;
            socklen_t addrlen;

            /* Retrieve the local address and port of the socket */
            getsockname(sockfd, (struct sockaddr *) &addr, &addrlen);

            /* Convert the address to a human-readable form and print it */
            char buffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &addr.sin_addr, buffer, INET_ADDRSTRLEN);
            printf("Local address: %s\n", buffer);
            printf("Local port: %d\n", ntohs(addr.sin_port));

    ####################
    # getprotobyname() #
    ####################
        retrieves the protocol number associated with a protocol name, specially network protocol as TCP

            #include <netdb.h>
            struct protoent *getprotobyname(const char *name);

        name = pointer to a null-terminated string containing the name of the protocol
        returns a pointer to a protoent structure containing informations about the protocol
        returns a null pointer if fails, if success the strucure contains data
        ex:
            #include <netdb.h>

            struct protoent *protocol;

            /* Lookup the protocol number for TCP */
            protocol = getprotobyname("tcp");

            /* Print the protocol number */
            printf("Protocol number for TCP: %d\n", protocol->p_proto);

        ############################################################################################
        YOU CAN USE this function with socket() function to create a socket with a specific protocol

        #include <sys/types.h>
        #include <sys/socket.h>
        #include <netdb.h>

        int sockfd;
        struct protoent *protocol;

        /* Lookup the protocol number for TCP */
        protocol = getprotobyname("tcp");

        /* Create a socket for the TCP protocol */
        sockfd = socket(AF_INET, SOCK_STREAM, protocol->p_proto);
        ############################################################################################

    ###################
    # gethostbyname() #
    ###################
        retrieves the host information associated with a hostname, typically the IP adress(es)

            #include <netdb.h>
            struct hostent *gethostbyname(const char *name)

        name = pointer to a null-terminated string containing the hostname
        returns a hostent structure containing the hostname informations
        if success, the histent structure will contain the IP address(es), hostname, aliases
        if fails, returns a null pointer
        ex:
            #include <netdb.h>
            #include <stdio.h>
            #include <arpa/inet.h>

            struct hostent *host;
            struct in_addr **addr_list;
            char ip[INET_ADDRSTRLEN];

            /* Lookup the host information for www.example.com */
            host = gethostbyname("www.example.com");

            /* Print the IP address(es) for the host */
            addr_list = (struct in_addr **) host->h_addr_list;
            for (int i = 0; addr_list[i] != NULL; i++) {
                inet_ntop(AF_INET, addr_list[i], ip, INET_ADDRSTRLEN);
                printf("%s\n", ip);
            }

        this example look up the IP address for the host ̈́ www.example.com' and prints them
        the IP addresses are stored in the h_addr_list field of the hostent structure and converted to human-readable form with inet_ntop() function

        ############################################################################################
        YOU CAN USE gethostbyname() with connect() function to connect to a server using its hostname
        #include <sys/types.h>
        #include <sys/socket.h>
        #include <netdb.h>
        #include <arpa/inet.h>

        int sockfd;
        struct sockaddr_in server;
        struct hostent *host;

        /* Lookup the host information for www.example.com */
        host = gethostbyname("www.example.com");

        /* Initialize the server address structure */
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(80);
        memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);

        /* Create a socket and connect to the server */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        connect(sockfd, (struct sockaddr *) &server, sizeof(server));
        ############################################################################################

    #################
    # getaddrinfo() #
    #################
        resolves hostname and service name to sockets addresses.
        it's a more modern and flexible version of gethostbyname() and getservbyname() functions
        resolves with connect(), bind() and accept()

            #include <netdb.h>
            + #include <sys/types.h> (for socket creation after resolving)
            + #include <sys/socket.h> (for socket creation after resolving)
            + #include <string.h> (for memset())
            int getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res);

        node = pointer to a null-terminated string containing the hostname or address for which 
            you want to resolve the socket address
        service = pointer to a null-terminated string containing the service name or port number
            for which you want to resolve the socket address
        hints = pointer to addrinfo structure containing hints about the type of socket address
            you are looking for
        res = pointer to a pointer to an addrinfo structure which will be filled in with a
            linked list of resolved socket addresses on success
        returns 0 if success, and a non-zero code on failure
        use gai_strerror() function to convert the error code to a human-readable string
        ex:
            #include <sys/types.h>
            #include <sys/socket.h>
            #include <netdb.h>
            #include <stdio.h>
            #include <string.h>

            int main(int argc, char **argv) {
                int sockfd;
                struct addrinfo hints, *res;
                int status;

                /* Set the hints for the type of socket we want */
                memset(&hints, 0, sizeof(hints));
                hints.ai_family = AF_UNSPEC;  /* Allow IPv4 or IPv6 */
                hints.ai_socktype = SOCK_STREAM;  /* Stream socket */
                hints.ai_flags = AI_PASSIVE;  /* For wildcard IP address */

                /* Resolve the hostname and service name to a socket address */
                status = getaddrinfo(argv[1], argv[2], &hints, &res);
                if (status != 0) {
                    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
                    return 1;
                }

                /* Create a socket and connect to the server */
                sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
                if (sockfd == -1) {
                    perror("socket");
                    return 1;
                }
                if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
                    perror("connect");
                    return 1;
                }

                /* Free the resolved socket address */
                freeaddrinfo(res);

                /* ... */
            }
        This example resolves the socket address for the hostname and service name specified on the command line (argv[1] and argv[2]) using getaddrinfo()

    ##################
    # freeaddrinfo() #
    ##################
        frees the memory allocated by getaddrinfo() function

            #include <netdb.h>
            void freeaddrinfo(struct addrinfo *res);

        res = pointer to the head of the linked list addrinfo structures that was returned by getaddrinfo()
        it does not clise any open socket or release any other resources

    ##########
    # bind() #
    ##########
        assign a name to a socket, typically used on the server side of a network application
        is called after the socket has been created with socket() function
        
            #include <sys/socket.h>
            int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
        
        sockfd = socket file descriptor (non-negative integer)
        addr = pointer to a sockaddr structure that contains the address information for the socket
                the type of the structure depends on the address family (here sockadrr_in for IPv4)
        addrlen = size of the address structure in bytes
        returns 0 on success, -1 if error, using/setting errno global variable to indicate the error

        struct sockaddr_in
        {
            sa_family_t     sin_family;         // Address family (AF_INET for IPv4)
            uint15_t        sin_port;           // Port number (in network byte order)
            struct in_addr  sin_addr;           // IPv4 address (in network byte order)
            char            sin_zero[8]         // Padding to make structure the same size as sockaddr   
        }
        #include <netinet/in.h>

    #############
    # connect() #
    #############
        used to establish a connection to a remote host on a network, typically used on the client side of a network application
        is called after socket creation with socket() function and after the socket address has been resolved using the getaddrinfo() function

            #include <sys/types.h>
            #include <sys/socket.h>
            int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

        sockfd = socket file descriptor (non-negative integer)
        addr = pointer to a sockaddr structure that contains the address information for the socket
                the type of the structure depends on the address family (here sockadrr_in for IPv4)
        addrlen = size of the address structure in bytes
        returns 0 on success, -1 if error, using/setting errno global variable to indicate the error

        struct sockaddr_in
        {
            sa_family_t     sin_family;         // Address family (AF_INET for IPv4)
            uint15_t        sin_port;           // Port number (in network byte order)
            struct in_addr  sin_addr;           // IPv4 address (in network byte order)
            char            sin_zero[8]         // Padding to make structure the same size as sockaddr   
        }
    ############
    # listen() #
    ############
        used to listen for incoming connections on a socket, typically used on the server side of a network application
        is called after socket creation with socket() function and a name has been assigned to the socket with the bind() function

            #include <sys/socket.h>
            int listen(int sockfd, int backlog)
    
        sockfd = socket file descriptor
        backlog = maximum number of pending connections that the socket can hold.
            When a connection request is received and the queue is full, the client may receive an error

    ############
    # accept() #
    ############
        used to accept an incoming connection on a socket, typically used on the server side of a network application
        is called after socket creation with socket() function and a name has been assigned to the socket 
        with the bind() function and the socket has begun listening for incoming connections with the listen() function

            #include <sys/socket.h>
            int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

        sockfd = socket file descriptor (non-negative integer)
        addr = pointer to a sockaddr structure that contains the address information for the socket
                the type of the structure depends on the address family (here sockadrr_in for IPv4)
        addrlen = size of the address structure in bytes
        returns 0 on success, -1 if error, using/setting errno global variable to indicate the error
        struct sockaddr_in
        {
            sa_family_t     sin_family;         // Address family (AF_INET for IPv4)
            uint15_t        sin_port;           // Port number (in network byte order)
            struct in_addr  sin_addr;           // IPv4 address (in network byte order)
            char            sin_zero[8]         // Padding to make structure the same size as sockaddr   
        }

        ex:
            #include <iostream>
            #include <sys/types.h>
            #include <sys/socket.h>
            #include <netinet/in.h>
            #include <unistd.h>
            #include <arpa/inet.h>

            int main() {
              int server_fd, client_fd;
              sockaddr_in server_address, client_address;
              socklen_t client_address_size;

              server_fd = socket(AF_INET, SOCK_STREAM, 0);

              server_address.sin_family = AF_INET;
              server_address.sin_port = htons(6667);
              server_address.sin_addr.s_addr = INADDR_ANY;

              bind(server_fd, (sockaddr*)&server_address, sizeof(server_address));
              listen(server_fd, 5);

              client_address_size = sizeof(client_address);
              client_fd = accept(server_fd, (sockaddr*)&client_address, &client_address_size);

              std::cout << "Connected to client with IP address: " << inet_ntoa(client_address.sin_addr) << std::endl;

              close(client_fd);
              close(server_fd);

              return 0;
            }
            In the example above, the server creates a socket and binds it to a particular port and IP address. It then listens for incoming connections on that socket. When a connection request arrives, the accept() function is called to create a new socket for the connection and return a descriptor for the new socket. The IP address of the client is then printed to the console. Finally, both the original socket and the new socket are closed.

    ###########
    # htons() #
    ###########
        converts a 16-bits interger from host byte order to network byte order, typically used when sending or receiving data over a network that uses TCP/IP, as the network byte order is defined as big-endian, while the host byte order may be either big-endian or little-endian depending on the plateform

            #include <arpa/inet.h>
            uint16_t htons(uint16_t hostshort);
        
        hostshort = 16-bit integer in hist byte order
        returns the equivalent value in network byte order

        ex:
            #include <arpa/inet.h>
            #include <stdio.h>

            int main(int argc, char *argv[]) {
                uint16_t port;

                /* Read the port number from the command line */
                if (argc < 2) {
                    fprintf(stderr, "Usage: %s port\n", argv[0]);
                    return 1;
                }
                port = (uint16_t)atoi(argv[1]);

                /* Convert the port number to network byte order */
                port = htons(port);

                /* ... */
            }    
        This example reads a port number from the command line and converts it to network byte order using the htons() function. The converted port number can then be used in a bind() call to bind a socket to the specified port, or in a connect() call to connect to a server on the specified port.
        There are also similar functions for converting other data types from host byte order to network byte order, such as htonl() for 32-bit integers and htont() for 64-bit integers.

    ###########
    # ntohs() #
    ###########
        opposite of htons() function
        converts a 16-bit integer from network byte order to host byte order, typically used when receiving data over a network that uses TCP/IP

            #include <arpa/inet.h>
            uint16_t ntohs(uint16_t netshort);
        
        ex:
            #include <arpa/inet.h>
            #include <stdio.h>

            int main(int argc, char *argv[]) {
                uint16_t port;

                /* Receive the port number from the network */
                /* ... */

                /* Convert the port number to host byte order */
                port = ntohs(port);

                /* ... */
            }   
        This example receives a port number over the network and converts it to host byte order using the ntohs() function. The converted port number can then be used in a bind() call to bind a socket to the specified port, or in a connect() call to connect to a server on the specified port.
        There are also similar functions for converting other data types from network byte order to host byte order, such as ntohl() for 32-bit integers and ntoht() for 64-bit integers.
    
    ###########
    # ntohl() #
    ###########
        opposite of htonl() function
        converts a 32-bit integer from network byte order to host byte order, typically used when receiving 
        data over a network that uses TCP/IP
            
            #include <arpa/inet.h>
            uint32_t ntohl(uint32_t netlong);
        
        netlong = 32-bit integer in network byte order
        ex:
            #include <arpa/inet.h>
            #include <stdio.h>

            int main(int argc, char *argv[]) {
                uint32_t value;

                /* Receive the value from the network */
                /* ... */

                /* Convert the value to host byte order */
                value = ntohl(value);

                /* ... */
            }
        This example receives a 32-bit value over the network and converts it to host byte order using the ntohl() function. The converted value can then be used in your program as needed.

        There are also similar functions for converting other data types from network byte order to host byte order, such as ntohs() for 16-bit integers and ntoht() for 64-bit integers.

    ###############
    # inet_addr() #
    ###############
        converts a string containing an Internet Protocol address in presentation format to its binary representation in network byte order, typically used to convert IP addresses specified in human -readable form (ex: 192.0.2.1) into a form that can be used by network functions

            #include <arpa/inet.h>
            in_addr_t inet_addr(const char *cp);

            cp = a pointer to a null-terminated string containing the IP address in the 'dotted-decimal' notation
            returns a 32-bits integer representing the IP address in the network byte order.
            If the input string is not a valid IP address, the function returns a special constant 'INADDR_NONE' which is typically defined as -1

        ex:
            #include <arpa/inet.h>
            #include <stdio.h>

            int main() {
              char *ip_str = "192.0.2.0";
              in_addr_t ip = inet_addr(ip_str);
              if (ip == INADDR_NONE) {
                printf("Invalid IP address\n");
              } else {
                printf("IP address: %u\n", ip);
              }
              return 0;
            }

        ex:
            #include <arpa/inet.h>
            #include <stdio.h>

            int main(int argc, char *argv[]) {
              if (argc != 2) {
                printf("Usage: %s <IP address>\n", argv[0]);
                return 1;
              }
              unsigned long addr = inet_addr(argv[1]);
              if (addr == INADDR_NONE) {
                printf("Invalid IP address\n");
                return 1;
              }
              printf("Address: %lu\n", addr);
              return 0;
            }

            ex: the following code snippet creates a socket and binds it to the IP address '192.0.2.0' and port 8080
                #include <arpa/inet.h>

                int sockfd;
                struct sockaddr_in server_addr;

                sockfd = socket(AF_INET, SOCK_STREAM, 0);

                server_addr.sin_family = AF_INET;
                server_addr.sin_port = htons(8080);
                server_addr.sin_addr.s_addr = inet_addr("192.0.2.0");

                bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr));            

            NB: it's a deprecated function => better use of inet_pton(), more flexible and portable


    ###############
    # inet_ntoa() #
    ###############
        converts an IP address from its numerical representation in the network byte order to a string in the 'dotted-decimal' notation

            #include <arpa/inet.h>
            char *inet_ntoa(struct in_addr in);

        in = structure that contains the IP address in the network byte order
        returns a pointer to a null-terminated string containing the IP address in the 'dotted-decimal' notation

        ex:
            #include <arpa/inet.h>
            #include <stdio.h>

            int main() {
              struct in_addr ip;
              ip.s_addr = htonl(0xc0000200);
              char *ip_str = inet_ntoa(ip);
              printf("IP address: %s\n", ip_str);
              return 0;
            }        
        output:
            IP address: 192.0.2.0
        
        NB: inet_ntoa() is not thread-safe and should not be used in multithreaded prograns. the string returned by it is statically allocated and will be overwritten by subsequent calls to the function. If you need to retain the string, you should make a copy of it
        It's a deprecated function => better use inet_ntop(), more flexible and portable

    ##########
    # send() #
    ##########
        used to transmit data over a network. It's part of the Berkeley sockets API and is available on most plateforms

            #include <>
            ssize_t send(int sockfd, const void *buf, size_t len, int flags);

        sockfd = a socket descriptor representing the socket to which the data should be transmitted
        buf = a pointer to the buffer containing the data to be transmitted
        len = the length of the data in the buffer, in bytes
        flags = a set of flags that specify options for the transmission
        returns the number of bytes transmitted, -1 if an error occured

    ##########
    # recv() #
    ##########
        used to receive data on a socket. 

            #include <sys/socket.h>
            int recv(int sockfd void *buf, int len, int flags);

        sockfd = file descriptor of the socket on which data is to be received
        buf = pointer to a buffer where the received data will be stored
        len = maximum number of bytes to be received
        flags = set of flags to specify options for the function
        returns the number of bytes received, -1 if an error occured

        ex:
            #include <sys/socket.h>
            #include <netinet/in.h>
            #include <arpa/inet.h>
            #include <stdio.h>
            #include <stdlib.h>
            #include <unistd.h>
            #include <errno.h>
            #include <string.h>

            int main(void)
            {
                int sockfd = 0, n = 0;
                char recvBuff[1024];
                struct sockaddr_in serv_addr;

                memset(recvBuff, '0', sizeof(recvBuff));
                if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
                {
                    printf("\n Error : Could not create socket \n");
                    return 1;
                }

                memset(&serv_addr, '0', sizeof(serv_addr));

                serv_addr.sin_family = AF_INET;
                serv_addr.sin_port = htons(6667);

                if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
                {
                    printf("\n inet_pton error occured\n");
                    return 1;
                }

                if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
                {
                    printf("\n Error : Connect Failed \n");
                    return 1;
                }

                while((n = recv(sockfd, recvBuff, sizeof(recvBuff)-1, 0)) > 0)
                {
                    recvBuff[n] = 0;
                    if(fputs(recvBuff, stdout) == EOF)
                    {
                        printf("\n Error : Fputs error\n");
                    }
                }

                if(n < 0)
                {
                    printf("\n Read error \n");
                }

                return 0;
            }
            This code creates a socket, connects to a remote host, then receives and print data from the host until there is no more data to be received.
            The function is called in a loop and the received data is stored in the recvBuff

    ############
    # signal() #
    ############
        used to specify a function (called the signal handler) to be called when a particular signal is received by the program
        Signals are used to communicate between processes and they can be generated by the operating system or by other processes

            #include <csignal>
            void (*signal(int sig, void (*func)(int)))(int);

        sig = signal number to be caught
        func = pointer to the signal handler function
        returns a pointer to the previous signal handler or SIG_ERROR if an error occurs

        ex:
            #include <csignal>
            #include <iostream>

            void signal_handler(int sig)
            {
                std::cout << "Caught signal " << sig << std::endl;
            }

            int main()
            {
                // Set the signal handler for SIGINT
                if (signal(SIGINT, signal_handler) == SIG_ERR)
                {
                    std::cout << "Error setting signal handler" << std::endl;
                    return 1;
                }

                // Wait for a signal to be received
                pause();

                return 0;
            }
            This program sets a signal handler function for the SIGINT signal (which is enerated when the user presses CTRL+C)
            When the signal is received, the signal handler function is called and a message is printed
            The program then waits for another signal to be received using the pause() funtion

    ###########
    # lseek() #
    ###########
        used to reposition the file offset of a file descriptor. The file offset is a value that specifies the current position in the file and lseek() cans be used to move the file offset to a new position

            #include <unistd.h>
            off_t lseek(int d, off_t offset, int whence);
        
        fd = file descriptor of the file for which the file offset is to be changed
        offst = number of bytes to move the file offset
        whence = value that specifies how the offset argument is to be interpreted:
            SEEK_SET = the file offset is set to offset bytes from the beginning of the file
            SEEK_CUR = the file offset is set to its current location plus offset bytes
            SEEK_END = the file offset is set to offset bytes from the end of the file
        returns the new file offset or -1 if n error occurs

    ex:
        #include <unistd.h>
        #include <fcntl.h>
        #include <iostream>

        int main()
        {
            int fd = open("file.txt", O_RDONLY);
            if (fd == -1)
            {
                std::cout << "Error opening file" << std::endl;
                return 1;
            }

            // Set the file offset to 10 bytes from the beginning of the file
            off_t offset = lseek(fd, 10, SEEK_SET);
            if (offset == -1)
            {
                std::cout << "Error seeking in file" << std::endl;
                return 1;
            }

            // Read and print the next 10 bytes of the file
            char buffer[10];
            ssize_t n = read(fd, buffer, sizeof(buffer));
            if (n == -1)
            {
                std::cout << "Error reading from file" << std::endl;
                return 1;
            }
            std::cout.write(buffer, n);

            close(fd);
            return 0;
        }
        This program opens a file, uses lseek() o set the file offset to 10 bytes from the beginning of the file and then reads and prints the next 10 bytes of the file

    ###########
    # fstat() #
    ###########
        used to obtain information about a file based on its file descriptor

            #include <sys/stat.h>
            int fstat(ont fd, struct stat *buf);
        
        fd = file descriptor for the file for which information is desire
        buf = pointer to astruct stat object where the information about the file will be stored
        returns 0 if success, -1 if fail and sets the errno global variable to indicate the error

        ex:
            #include <sys/stat.h>
            #include <unistd.h>
            #include <iostream>
            #include <fstream>

            int main(int argc, char* argv[]) {
              std::ifstream file(argv[1]);
              int fd = file.rdbuf()->fd();
              struct stat sb;

              // Obtain information about the file
              if (fstat(fd, &sb) == -1) {
                std::cerr << "Error obtaining information about file" << std::endl;
                return 1;
              }

              // Print the file size
              std::cout << "File size: " << sb.st_size << std::endl;

              file.close();
              return 0;
            }
            This code opens a file specified as the first command line argument using an ifstream object then uses the rdbuf() method to obtain the file descriptor for the file. It then calls fstat() to obtain information about the file and stores it in a struct stat object. finally it prints the size of the file to the console
            You can access other fields in the struct stat object to obtain other information about the file, such as its permissions or timestamps. See the <sys/stat.h> header file or the documentation for a complete list of fields in the struct stat object

    ###########
    # fcntl() #
    ###########
        used to manipulate file descriptor flags

            #include <fcntl.h>
            int fcntl(int fd int cmd, .../*arg*/);
        
        fd = file descriptor for the file you want to manipulate
        cmd = a integer value that specifies the operation to be performed
            F_DUPFD = duplicate a file descriptor
            F_GETFD = get the file descriptor flags
            F_SETFD = set the file descriptor flags
            F_GETFL = get the file status flags
            F_SETFL = set the file status flags
        arg = a value that is used as an argument for the specified operation
        returns a value that depends on the specific operation being performed if success
        if fail, returns -1 and sets the errno global variable to indicate the error

        ex:
            #include <fcntl.h>
            #include <unistd.h>
            #include <iostream>
            #include <fstream>

            int main(int argc, char* argv[]) {
              std::ifstream file(argv[1]);
              int fd = file.rdbuf()->fd();

              // Set the file status flags to make the file non-blocking
              int flags = fcntl(fd, F_GETFL, 0);
              fcntl(fd, F_SETFL, flags | O_NONBLOCK);

              file.close();
              return 0;
            }
            This code opens a file specified as the first command-line argument using an ifstream object, then uses the rdbuf() method to obtain the file descriptor for the file. It then calls fcntl() with the F_GETFL command to obtain the current file status flags, and then calls fcntl() again with the F_SETFL command to set the O_NONBLOCK flag, which makes the file non-blocking.

    ##########
    # poll() #
    ##########
        used to monitor multiple file descriptors for events

            #include <poll.h>
            int poll(struct pollfd *fds, nfds_t nfds, int timeout);
        
        fds = pointer to an array of struct pollfd objects. each object represents a file descriptor to be monitored and
            contains the following fields:
                fd = file descriptor to be monitored
                events = a bit mask that specifies the events to be monitored for the file descriptor
                revents =  bit mask that is set by the function to indicate the events that have occured for the file descriptor
        nfds = the number of file decriptors in the fds array
        timeout = the number of milliseconds to wait for an event to occur
            if timeout is -1, the function will block indefinitely until an event occurs
            if timeout is 0, the function will return immediately without waiting
        returns an int value:
            if function successful and an event occured on one of the file descriptors,
                it returns the number of file descriptors with events
            if function successful and timeout expired, it returns 0
            if function unsuccesful, it returns -1 and sets the rrno global variable to indicate the error
        
        ex:
            #include <poll.h>
            #include <unistd.h>
            #include <iostream>
            #include <fstream>

            int main(int argc, char* argv[]) {
              std::ifstream file(argv[1]);
              int fd = file.rdbuf()->fd();

              struct pollfd pfd;
              pfd.fd = fd;
              pfd.events = POLLIN;

              // Wait for data to become available for reading
              int timeout = 1000; // Timeout in milliseconds
              int ret = poll(&pfd, 1, timeout);
              if (ret == 0) {
                std::cout << "Timed out waiting for data" << std::endl;
              } else if (ret == -1) {
                std::cerr << "Error waiting for data" << std::endl;
              } else {
                if (pfd.revents & POLLIN) {
                  std::cout << "Data is available for reading" << std::endl;
                }
              }

              file.close();
              return 0;
            }
            This code opens a file specified as the first command-line argument using an ifstream object, then uses the rdbuf() method to obtain the file descriptor for the file. It then creates a struct pollfd object for the file descriptor and sets the events field to POLLIN, indicating that we are interested in events related to data becoming available for reading.
            The code then calls poll() with a timeout of 1000 milliseconds (1 second). If data becomes available for reading within the timeout period, poll() returns a positive value and the revents field of the struct pollfd object is set to indicate the events that have occurred. If the timeout expires, poll() returns 0. If an error occurs, poll() returns -1.

    ###########
    # epoll() #
    ###########
        is a Linux-specific API that is used to monitor multiple file descriptors for events

            #include <sys/epoll.h>
        
        To use epoll in C++, you will need to create an epoll instance using the epoll_create() function, add file descriptors to the instance using the epoll_ctl() function, and then wait for events to occur on the file descriptors using the epoll_wait() function.

            int epoll_create(int size);

                size = this argument i ignored but must be greater than 0
                returns an int value:
                    if function successful, returns a file decriptor for the new epoll instance
                    if unsuccessful, returns -1 and set the errno global variable to indicate the error 

            int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);

                epfd = file descriptor for the epoll instance
                op = operation to be performed:
                    EPOLL_CTL_ADD = add a file descriptor to the epoll instance
                    EPOLL_TL_MOD = modify the vents to be monitored for a file descriptor in the epoll instance
                    EPOLL_CTL_DEL = remove  a file descriptor from the epoll instance
                fd = the file descriptor to be added, modified or removed from the epoll instance
                event = pointer to a struct epoll_event object that contains the following fields:
                    events = a bit mask that specifies the events to be monitored for the file descriptor
                    data = a union that can be used to associate data with the file descriptor
                returns an int value, 0 if success, -1 if error and sets errno global variable
            
            int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);

                epfd = file descriptor for the epoll instance
                evants = pointer to an arrayof struct epoll_event objects that will ne filled in by the function
                    with information about the events that have occured
                maxevents = the maximum number of events that an bestored in the events array
                timeout = the number of milliseconds to wait for an event to occur
                    if timeout is -1, the function will block indefinitely until an event occurs
                    if timeout is 0, the function will return immediately without waiting
                returns an int value
                    if function successful and one or more avents occured,
                        it returns the number of events stored in the events array
                    if function successful and timeout expired, it returns 0
                    if function unsuccesful, it returns -1 and sets the rrno global variable to indicate the error

        ex: monitoring a file descriptor for data to beom available for reading
            #include <sys/epoll.h>
            #include <unistd.h>
            #include <iostream>
            #include <fstream>

            bool wait_for_data(int fd, int timeout) {
              // Create an epoll instance
              int epfd = epoll_create(1);
              if (epfd == -1) {
                std::cerr << "Error creating epoll instance" << std::endl;
                return false;
              }

              // Add the file descriptor to the epoll instance
              struct epoll_event event;
              event.events = EPOLLIN;
              event.data.fd = fd;
              if (epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event) == -1) {
                std::cerr << "Error adding file descriptor to epoll instance" << std::endl;
                return false;
              }

              // Wait for data to become available for reading
              struct epoll_event events[1];
              int ret = epoll_wait(epfd, events, 1, timeout);
              if (ret == 0) {
                std::cout << "Timed out waiting for data" << std::endl;
                return false;
              } else if (ret == -1) {
                std::cerr << "Error waiting for data" << std::endl;
                return false;
              } else {
                if (events[0].events & EPOLLIN) {
                  std::cout << "Data is available for reading" << std::endl;
                  return true;
                }
              }

              return false;
            }

            int main(int argc, char* argv[]) {
              std::ifstream file(argv[1]);
              int fd = file.rdbuf()->fd();
              int timeout = 1000; // Timeout in milliseconds

              if (wait_for_data(fd, timeout)) {
                // Read data from the file
              }

              file.close();
              return 0;
            }


##########################################
Launch server: ./ircserv <port> <password>
##########################################

################################################
Launch client in another terminal: irssi + emter
################################################

COMMANDES IRC
    run irssi dans le terminal
        irssi

    afficher la liste des servers
        /server list

    se connecter a un server
        /connect <nom server>

    configurer un pseudo
        /nick <pseudo>

    rejoindre/creer un salon de chat (existant/non existant)
        /join <nom salon>

    Ajouter un autre utilisateur
        ouvrir un autre terminal
        irssi
        /server list
        /connect <nom server>
        /nick <pseudo>
        /join <nom room>
        /subscribe <nom utilisateur dans salon different de pseudo> channel

    sortir d'un salon
        /exit

    Tuto youtube (C++ sockets - Create simple server and client chat Linux)
        https://www.youtube.com/watch?v=IydkqseK6oQ
        tester le dossier TutoC++ClientServer

    
DEFINITIONS:

    Socket: basic component of a server. allows your operating system to connect to a network in a particular way

    En C++ on cree une classe qui represente une socket et qui sera portable pour d'autres fonctions (un serveur, un client ou un reseau peer to peer)
    
    On doit creer une socket avec la fonction socket(AF_INET, SOCK_STREAM, 0)
        AF_INET = domain or address family
            AF_INET  -> IP
            AF_INET6 -> IPv6
            AF_UNIX  -> local channel, similar to pipes
            AF_ISO   -> ISO protocols
            AF_NS    -> Xerox Network Systems protocols
        SOCK_STREAM = type
            SOCK_STREAM -> virtual circuit service
            SOCK_DGRAM  -> datagram service
            SOCK_RAW    -> direct IP service
        0 = protocol to use un supporting the sockets operation
            For TCP/IP sockets, we want to specify the IP address family (AF_INET) and virtual service circuit (SOCK_STREAM). 
            Since there's only one form of virtual circuit servicem there are no variations of the protocol, so the last argument protocol is 0
    puis la bind a un reseau avec la fonction bind(server_fd, (...))
    puis listen avec la fonction listen(server_fd, ...)
    Pour chaque etape, check si error (== 0 ou < 0)
    The analogy of creating a socker is that of requesting a telehone line from the phone compagny
    
      
    
Notions pour coder un serveur http:
    - OSI (Open Systems Interconnection model) = modele theorique en 7 couches pour assurer la communication standardisee par des protocoles pour une interoperabilite

    - 4ene couche du modele OSI: Transport layer
    s'assure que les infos sont transmises d'un point A a un poitn B sans erreurs
    ex: TCP (Transmission Control Protocol), UDP (User Datagram Protocol), SPX (Sequenced Packet Exchange)
    
    - En general la communication http se fait avec les protocoles TCP/IP et le port 80 par defaut, meme si d'autre ports peuvent etre utilises (et UDP est plus rapide mais moins fiable)

    - RFC (Request For Comments) = official documents of Internet specifications, communications protocols, procedures and events

    - To implement HTTP server, read RFC 7230, 7231, 7232, 7233, 7234, 7235

IRC COMMANDS

    INVITE
    JOIN -
    KICK -
    LIST -
    NAMES -
    PART -
    TOPIC -
    MODE
    NICK -
    OPER -
    QUIT -
    USER -
    KILL -
    PING -
    PONG -
    PASS -
    PRIVMSG -
    NOTICE -
    MOTD -

    Optional:
    AWAY
    ISON
    USERHOST
    USERS
    WALLOPS
    ADMIN
    INFO
    LUSERS
    TIME
    VERSION
    WHO
    WHOIS
    WHOWAS

IRC MODES

    USER MODES:
        a : away
        i : invisible
        w : wallops
        r : restricted
        o : operator
    
    CHANNEL MODES:
        for users
            O : channel creator
            o : channel operator
            v : voice
        for channels
            i : invite only
            m : moderated
            n : outside privmsg disabled
            p : private
            t : topic locked
            k : key locked
            l : user limit

#############
IRC Wikipedia
#############
    IRC = "Discussion relayee par internet"
    C'est un protocole de communication textuel sur internet
    Pour la communication instantanee sous forme de discussions en groupes via des canaux de discussion et pour les communications privees entre deux personnes et aussi pour faire du transfert du fichier

########
RFC 2812 -> defines the Client Protocol
########

    Internet Relay Chat Protocol is for use with text based conferencing;
    the simpliest client being any socket program capable of connecting to the server

#################################################################################################
#                                        RAPPPEL C++                                            #
#################################################################################################

Declaration of a class in a canonical form

MyClass.hpp file:

    #ifndef MYCLASS_HPP

        # define MYCLASS_HPP

        # include <string>

        class MyClass
        {
        
            public:

                // Default Constructor
                MyClass(void);

                // Constructor with parameter 
                MyClass(int val, std::string str);

                // Copy Constructor
                MyClass(const MyClass &other);

                // Overload operator
                MyCLass operator=(const MyClass &other);
        
                // Accessor/getter functions
                int         getVal() const;
                std::string getStr() const;

            private:

                int             _val;
                std::string     _str;
        }

    #endif

MyClass.cpp file:

    #include "MyClass.hpp"

    // Constructor implementation
    MyClass::MyClass(int val, std::string str) : _val(val), _str(str)
    {
        std::cout << "Constructor called" << std::endl;
    }

    // Copy Constructor implementation
    MyClass::MyClass(const MyClass &other): _val(other._val), _str(other._str)
    {
        std::cout << "Copy Constructor called" << std::endl;
    }

    // Destructor implementation
    ~MyClass
    {
        std::cout << "Destructor called" << std::endl;
    }

    // Accessor/getter function implementation
    int             MyClass::getVal() const {return _val;}
    std::string     MyClass::getStr() const {return _str;}

    // Overload operator implementation
    MyClass MyClass::operator=(const MyClass &other)
    {
        
    }