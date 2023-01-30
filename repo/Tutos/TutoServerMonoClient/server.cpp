/*
Pour créer un serveur mono-client en C++, vous pouvez suivre les étapes suivantes :

Créez un socket pour le serveur en utilisant la fonction socket().
Liez le socket au port et à l'adresse IP souhaités en utilisant la fonction bind().
Écoutez les connexions entrantes en utilisant la fonction listen().
Acceptez une connexion entrante en utilisant la fonction accept().
Utilisez les fonctions de lecture et d'écriture de socket, telles que send() et recv(), pour envoyer et recevoir des données avec le client.
Fermez le socket du client et du serveur lorsque vous avez terminé de communiquer en utilisant la fonction close().
Voici un exemple de code qui met en œuvre ces étapes :

compiler avec g++ -std=c++98 server.cpp -o server

Il est important de noter que ce code ne gère pas les erreurs ni les cas où le client peut envoyer plusieurs requêtes au serveur.
Vous devrez ajouter du code pour gérer ces cas si nécessaire.
*/

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
  // Création du socket pour le serveur
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Structure de données pour stocker l'adresse et le port du serveur
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(6667);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // Liaison du socket au port et à l'adresse souhaités
  bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

  // Écoute des connexions entrantes
  listen(server_socket, 5);

  // Acceptation d'une connexion entrante
  int client_socket = accept(server_socket, NULL, NULL);

  // Envoi de données au client
  const char* message = "Hello, client!";
  send(client_socket, message, strlen(message), 0);

  // Fermeture du socket du client et du serveur
  close(client_socket);
  close(server_socket);

  return 0;
}
