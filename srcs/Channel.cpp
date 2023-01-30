#include "../includes/Channel.hpp"


/*=====================================================*/
/* 				CONTRUCTOR / DESTRUCTOR				   */
/*=====================================================*/

// création d'un channel sans password: 
Channel::Channel(std::string name): _name(name){
	this->addMode((char)208);
}

// ... + setModes
Channel::Channel(std::string name, char setModes): _name(name), _chanModes(setModes){
}

// création d'un channel avec password:
Channel::Channel(std::string name, std::string password): _name(name), _password(password){
	this->addMode((char)212);
}

// ... + setModes
Channel::Channel(std::string name, std::string password, char setModes): _name(name), _password(password), _chanModes(setModes){
}


// création d'un channel test avec userMap prédéfinie: 
Channel::Channel(std::string name, std::map<int, User *> usersMap): _name(name), _usersMap(usersMap){
	this->addMode((char)208);
}

// destructeur:
Channel::~Channel(){
}


/*=====================================================*/
/* 					     GETTER						   */
/*=====================================================*/

// récupérer la liste des utilisateurs connectés au channel:
std::map<int, User *>	Channel::getUsersMap() const{
	return (this->_usersMap);
}

// récupérer la liste des opérateurs du channel:
std::map<int, User *>	Channel::getOperatorsMap() const{
	return (this->_operatorsMap);
}

// récupérer la liste des users avec le droit de parler dans le channel:
std::map<int, User *>	Channel::getVoiceMap() const{
	return (this->_voiceMap);
}

// récupérer la liste des utilisateurs bannis du channel: 
std::map<int, User *>	Channel::getBanMap() const{
	return (this->_banMap);
}

// récupérer la liste des utilisateurs invités sur le channel: 
std::map<int, User *>	Channel::getInviteMap() const{
	return (this->_inviteMap);
}

// récupérer le nom du channel:
std::string				Channel::getName() const{
	return (this->_name);
}

// récupérer l'ID du channel: 
int						Channel::getID() const{
	return (this->_ID);
}

std::string				Channel::getPassword() const{
	return (this->_password);
}

// récupérer le topic du channel: 
std::string				Channel::getTopic() const{
	return (this->_topic);
}

// récupérer le nombre max d'utilisateurs autorisés à se connecter dans le channel: 
int						Channel::getMaxUsers() const{
	return (this->_maxUsers);
}

// récupérer un utilisateur à partir de son nom: 
User *					Channel::getUser(std::string nickname){
	std::map<int, User *>::iterator it;
	
	for (it = this->_usersMap.begin(); it != this->_usersMap.end(); it++){
		if (nickname.compare(it->second->getNickname()) == 0)
			return (it->second);
	}
	return (NULL);
}

// récupérer les modes du channel (ref par nbr):
char					Channel::getModes() const{
	return (this->_chanModes);
}

//récupérer les modes du channel (ref par lettres):
std::string				Channel::getStatus() const{
	return (this->_chanStatus);
}

//afficher les noms des users des users présent dans une map :
void			 		Channel::printUsersMap(std::map<int, User *> map){
	if (map.empty())
		std::cout << "The map is empty." << std::endl;
	else
	{
		for (std::map<int, User *>::iterator it = map.begin(); it != map.end(); it++){
			std::cout << "user fd : " << it->second->getUserSfd() << std::endl;
			std::cout << "username: " << it->second->getUsername() << std::endl;
			std::cout << "nickname: " << it->second->getNickname() << std::endl;
			std::cout << "hostname: " << it->second->getHostname() << std::endl;
			std::cout << "realname: " << it->second->getRealname() << std::endl;	
			std::cout << "usermode: " << it->second->getUserModes() << std::endl;	
			std::cout << "mode    : " << it->second->getUserStatus() << std::endl;
			std::cout << "channels: " << std::endl;
			if (it->second->getChannels().empty())
				std::cout << "- no joined channels for this user -" << std::endl;
			else
				it->second->printChannels();
		}
	}
}

// retourner un pointeur sur l'user d'une map s'il existe ou verifier son existence: 
User        	  *Channel::findUser(int sfd, std::map<int, User *> map)
{
    std::map<int, User *>::iterator it = map.find(sfd);
    if (it != map.end())
        return (it->second);
    return (NULL);
}

void 			  Channel::sendAllUsers(std::string msg){
	std::map<int, User*>::iterator it;
	for (it = this->_usersMap.begin(); it != this->_usersMap.end(); it++){
		send(it->first, msg.c_str(), msg.length(), MSG_CONFIRM);
	}
}


/*=====================================================*/
/* 					     SETTERS       	  		   	   */
/*=====================================================*/


/*	  				  SET PASSWORD		    	       */
/*=====================================================*/

// ajouter ou modifier le password : 
void					Channel::setPassword(std::string password){
	this->_password = password;
}


/*	  AJOUTER / SUPPRIMER UN USER DANS UNE LISTE       */
/*=====================================================*/

// ajouter un utilisateur dans le channel:
void					Channel::addUser(int sfd, User *user){
	this->_usersMap.insert(std::make_pair(sfd, user));
}

// ajouter un opérateur dans le channel:
void					Channel::addOperator(int sfd, User *user){
	this->_operatorsMap.insert(std::make_pair(sfd, user));
}

// ajouter un droit de parole à un utilisateur du channel:
void					Channel::addVoiced(int sfd, User *user){
	this->_voiceMap.insert(std::make_pair(sfd, user));
}

// ajouter un utilisateur à la liste des bannis du channel:
void					Channel::addBan(int sfd, User *user){
	this->_banMap.insert(std::make_pair(sfd, user));
}

// ajouter un utilisateur existant sur le serveur à rejoindre le channel:
void					Channel::addInvite(int sfd, User *user){
	this->_inviteMap.insert(std::make_pair(sfd, user));
}

// supprimer un utilisateur dans une des listes à partir de son sfd: 
void					Channel::removeUser(int sfd, std::map<int, User *> map){
	map.erase(sfd);
}


/*	   DEFINIR / MODIFIER DES PROPRIETES DU CHANNEL    */
/*=====================================================*/

// ajouter ou modifier un topic:
void					Channel::setTopic(std::string topic){
	this->_topic = topic;
}

// ajouter un nombre maximum d'utilisateurs:
void					Channel::setMaxUsers(int maxUsers){
	this->_maxUsers = maxUsers;
}

//activer un mode (forme binaire):
void					Channel::addMode(char to_add){
	this->_chanModes |= to_add;
	setStatus();
}

//désactiver un mode (forme binaire):
void					Channel::removeMode(char to_rmv){
	this->_chanModes |= to_rmv;
	setStatus();
}

//convertir les modes du channel sous forme de string:
void					Channel::setStatus(){
	this->_chanStatus = "";

	if (this->_chanModes & INVITE_MODE)
		this->_chanStatus += 'i';
	if (this->_chanModes & MODERATE_MODE)
		this->_chanStatus += 'm';
	if (this->_chanModes & PRIVATE_MODE)
		this->_chanStatus += 'p';
	if (this->_chanModes & KEY_MODE)
		this->_chanStatus += 'k';
	if (this->_chanModes & LIMITED_MODE)
		this->_chanStatus += 'l';
	if (this->_chanModes & NO_OUTSIDE_PRVMSG_MODE)
		this->_chanStatus += 'n';
	if (this->_chanModes & TOPIC_MODE)
		this->_chanStatus += 't';
	if (this->_chanModes & SECRET_MODE)
		this->_chanStatus += 's';
	if (this->_chanStatus != "")
		this->_chanStatus = "+" + this->_chanStatus;
}