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
#include<netdb.h> // TO ADD
        
int main(void)
{
    int     client, server;
    int     portNum = 1500; // Note the server and client IP are the same 
    bool    isExit = false;
    int     bufSize = 1024;
    char    buffer[bufSize];
    char    *ip = "127.0.0.1";

    struct  sockaddr_in server_addr;

    // init socket
    
    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0)
    {
        std::cout << "Error creating socket..." << std::endl;
        exit (1);
     }
    std::cout << "Client Socket created... " << std::endl;
        
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);
    
    // Connecting to server socket
    
    if (connect(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0)
    {
        std::cout << "Connecting to server..." << std::endl;
    }   
    recv(client, buffer, bufSize, 0);
    std::cout << "Connection confirmed" << std::endl;
    std::cout << "Enter # to end the connection" << std::endl;
        
    do{
        std::cout << "Client: ";
        do{
            std::cin >> buffer;
            send(client, buffer, bufSize, 0);
            if (*buffer == '#')
            {
                send(client, buffer, bufSize, 0);
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != 42);
            std::cout << "Server: " << std::endl;
            do{
                recv(client, buffer, bufSize, 0);
                std::cout << buffer << " ";
                if (*buffer == '#')
                {
                    *buffer = '*';
                    isExit = true;
                }
            } while (*buffer != 42); 
            std::cout << std::endl;
    } while (!isExit);

    std::cout << "Connection terminated..." << std::endl;
    std::cout << "Goddbye..." << std::endl;
    close(client);
    return (0);
}