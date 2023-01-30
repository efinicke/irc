/*
https://www.youtube.com/watch?v=IydkqseK6oQ

Le serveur n'a pas besoin de connaitre le numero de port du client mais le 
client doit connaitre le numero de port du serveur
Ouvrir deux fenetres de terminal comme dans minitalk
fenetre 1:
    g++ server.cpp -o server
    ./server
fenetre 2:
    g++ client.cpp -o client
    
Envoyer des messages entre les deux fenetres
Quitter avec #
*/

// Basic socker header files
#include<iostream>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    int     client, server;
    int     portNum = 1500;
    bool    isExit = false;
    int     bufSize = 1024;
    char    buffer[bufSize];
    struct  sockaddr_in server_addr;
    socklen_t   size;
    // init socket
    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0)
    {
        std::cout << "Error establishing connection." << std::endl;
        exit (1);
     }
        
    std::cout << "Server Socket Connection created... " << std::endl;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);
    if (bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        std::cout << "Error binding socket..." << std::endl;
        exit(1);
    }
    
    size = sizeof(server_addr);
    std::cout << "Looking for clients..." << std::endl;
    // listening to socket
    listen(client, 1);
    // accept client
    server = accept(client, (struct sockaddr*)&server_addr, &size);
    if (server < 0)
    {
        std::cout << "Error on accepting..." << std::endl;
        exit(1);
    }
    while (server > 0)
    {
        strcpy(buffer, "Server connected...\n");
        send(server, buffer, bufSize, 0);
        std::cout << "Connected with client..." << std::endl;
        std::cout << "Enter # to end the connection" << std::endl;
        std::cout << "client: " << std::endl;
        do {
            recv(server, buffer, bufSize, 0);
            std::cout << "buffer" << " ";
            if (*buffer == '#')
            {
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != '*');
        do{
            std::cout << "\nServer: ";
            do {
                std::cin >> buffer;
                send(server, buffer, bufSize, 0);
                if (*buffer == '#')
                {
                    send(server, buffer, bufSize, 0);
                    *buffer = '*';
                    isExit = true;
                }
            } while (*buffer != '*');
            std::cout << "Client: ";
            do {
                recv(server, buffer, bufSize, 0);
                std::cout << buffer << " ";
                if (*buffer == '#')
                {
                    *buffer == '*';
                    isExit = true;
                }
            } while (*buffer != '*');
        } while (!isExit);
        std::cout << "Connection terminated..." << std::endl;
        std::cout << "Goodbye..." << std::endl;
        isExit = false;
        exit(1);
    }
    close(client);
    return (0);
}