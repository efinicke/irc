#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "./include.hpp"
#include "./User.hpp"

enum	chanModes
{
	INVITE_MODE     				=  1,    // 0000 0001,  i invite        1 si le chan est en mode invite only
	MODARATE_MODE   				=  2,    // 0000 0010,  m moderated     1 si le mode est modéré, CAD que seuls les op et les users autorisés à parler (voiced, mode +v) pouvent parler sur le chan
	PRIVATE_MODE    				=  4,    // 0000 0100,  p private       1 si le channel est en mode privé (le topic ne doit pas etre affiché)
	KEY_MODE        				=  8,    // 0000 1000,  k key           1 si un password a été assigné au channel
	SECRET_MODE     				=  16,   // 0001 0000,  s secret        1 si le le mode secret du chan est activé (/MODE +)
	LIMITED_MODE    				=  32,   // 0010 0000,  l users limit   1 si nombre limite d'utilisateurs est défini(/MODE +l [nbr])
	TOPIC_MODE      				=  64,   // 0100 0000,  t topic		    1 si seuls les ChannelOperator peuvent changer le topic
	NO_OUTSIDE_PRVMSG_MODE          =  128   // 1000 0000,  n outside pvmsg 1 si les messages privés sont interdits en dehors du chan
}; //nts par defaut = 208

class	Channel
{
	private:
		
		std::string					_name; // nom du channel
		int							_ID; //identifiant du channel
		std::string					_password; // mot de passe du channel
		std::string					_topic; // sujet du channel
		int							_maxUsers; // nombre maximum d'utilisateurs autorisés à se connecter sur ce channel

		std::map<int, User *>		_usersMap; // liste des utilisateurs connectés au channel
		std::map<int, User *>		_operatorsMap; // liste des opérateurs connectés sur le channel
		std::map<int, User *>		_voiceMap; // liste des users autorisés à parler sur le chan, en dehors des opérateurs
		std::map<int, User *>		_banMap; // liste des users bannis
		std::map<int, User *>		_inviteMap; // liste des users invités dans le chan

		char						_chanModes;  // format binaire qui indique les modes du channel.
		std::string					_chanStatus; // contient les modes du channel sous forme de string à afficher lors de /list


	public:

		// CONTRUCTOR / DESTRUCTOR
		Channel(std::string name);
		Channel(std::string name, std::string password);
		Channel(std::string name, std::map<int, User *> usersMap);
		Channel();
		~Channel(void);

		// *** GETTERS ***
		std::string				getName() const;
		int						getID() const;
		std::string				getTopic() const;
		int						getMaxUsers() const;
		User *					getUser(std::string user);

		std::map<int, User *>	getUsersMap() const;
		std::map<int, User *>	getOperatorsMap() const;
		std::map<int, User *>	getVoiceMap() const;
		std::map<int, User *>	getBanMap() const;
		std::map<int, User *>	getInviteMap() const;

		char					getModes() const; // modes du channel (code numérique)
		std::string 			getStatus() const; // modes du channel (lettres)
		void			 		printMap(std::map<int, User *> map); //afficher map


		// *** SETTERS ***
		// 	AJOUTER UN USER A UNE LISTE: 
		void	addUser(int id, User *user);
		void	addOperator(int id, User *user);
		void	addVoiced(int id, User *user);
		void	addBan(int id, User *user);
		void	addInvite(int id, User *user);

		// SUPPRIMER UN UTILISATEUR D'UNE LISTE: 
		void	removeUser(User *user, std::map<int, User *> map);
		
		// 	DEFINIR DES PROPRIETES AU CHANNEL: 
		void	setTopic(std::string topic);
		void	setMaxUsers(int maxUsers);
		void	addMode(char to_add);
		void	removeMode(char to_rmv);
		void	setStatus(); // maj automatique avec addMode() et rmvMode()
};

#endif

/*
void	Channel::sendToChanUsers(std::string const &msg){
	std::map< int, User *>::iterator it;

	for (it = _usersMap.begin(); it != _usersMap.end(); it++){
		//send(it->second->getUserId), msg.c_str(), msg.length(), MSG_CONFIRM);
	}
}

void			Channel::printMap(std::map<int, User *> map)
{
	if (!map.empty()){
		for (std::map<int, User *>::iterator it = map.begin(); it != map.end(); it++)
			it->second->printMap();
	}
	else
		std::cout << "empty map." << std::endl; 
}
*/