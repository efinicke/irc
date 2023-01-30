/*
Pour créer un client pour le serveur mono-client en C++, vous pouvez suivre les étapes suivantes :

Créez un socket pour le client en utilisant la fonction socket().
Remplissez la structure de données sockaddr_in avec l'adresse et le port du serveur.
Établissez une connexion au serveur en utilisant la fonction connect().
Utilisez les fonctions de lecture et d'écriture de socket, telles que send() et recv(), pour envoyer et recevoir des données avec le serveur.
Fermez le socket du client lorsque vous avez terminé de communiquer avec le serveur en utilisant la fonction close().
Voici un exemple de code qui met en œuvre ces étapes :

compiler avec g++ -std=c++98 client.cpp -o client
*/

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
  // Création du socket pour le client
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Structure de données pour stocker l'adresse et le port du serveur
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(6667);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // Établissement de la connexion au serveur
  connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address));

  // Réception de données du serveur
  char response[256];
  recv(client_socket, &response, sizeof(response), 0);
  std::cout << "Received: " << response << std::endl;

  // Fermeture du socket du client
  close(client_socket);

  return 0;
}
