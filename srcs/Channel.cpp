#include "../includes/Channel.hpp"


/*=====================================================*/
/* 				CONTRUCTOR / DESTRUCTOR				   */
/*=====================================================*/

// création d'un channel sans password: 
Channel::Channel(std::string name): _name(name){
	this->addMode(208);
}

// création d'un channel avec password:
Channel::Channel(std::string name, std::string password): _name(name), _password(password){
	this->addMode(212);
}

// création d'un channel test avec userList prédéfinie: 
Channel::Channel(std::string name, std::map<int, User> usersList): _name(name), _usersList(usersList){
	this->addMode(208);
}

// destructeur:
Channel::~Channel(void){
}


/*=====================================================*/
/* 					     GETTER						   */
/*=====================================================*/

// récupérer la liste des utilisateurs connectés au channel:
std::map<int, User>	Channel::getUsersList(){
	return (this->_usersList);
}

// récupérer la liste des opérateurs du channel:
std::map<int, User>	Channel::getOperatorsList(){
	return (this->_operatorsList);
}

// récupérer la liste des users avec le droit de parler dans le channel:
std::map<int, User>	Channel::getVoiceList(){
	return (this->_voiceList);
}

// récupérer la liste des utilisateurs bannis du channel: 
std::map<int, User>	Channel::getBanList(){
	return (this->_banList);
}

// récupérer la liste des utilisateurs invités sur le channel: 
std::map<int, User>	Channel::getInviteList(){
	return (this->_inviteList);
}

// récupérer le nom du channel:
std::string			Channel::getName(){
	return (this->_name);
}

// récupérer l'ID du channel: 
int					Channel::getID(){
	return (this->_ID);
}

// récupérer le topic du channel: 
std::string			Channel::getTopic(){
	return (this->_topic);
}

// récupérer le nombre max d'utilisateurs autorisés à se connecter dans le channel: 
int					Channel::getMaxUsers(){
	return (this->_maxUsers);
}

// récupérer les modes du channel (ref par nbr):
int					Channel::getModes(){
	return (this->_chanModes);
}

//récupérer les modes du channel (ref par lettres):
std::string			Channel::getStatus(){
	return (this->_chanStatus);
}


/*=====================================================*/
/* 					     SETTERS       	  		   	   */
/*=====================================================*/



/*		   AJOUTER UN USER DANS UNE LISTE        	   */
/*=====================================================*/

// ajouter un utilisateur dans le channel:
void	Channel::addUser(int id, User user){
	this->_usersList.insert(std::make_pair(id, user));
}

// ajouter un opérateur dans le channel:
void	Channel::addOperator(int id, User user){
	this->_operatorsList.insert(std::make_pair(id, user));
}

// ajouter un droit de parole à un utilisateur du channel:
void	Channel::addVoiced(int id, User user){
	this->_voiceList.insert(std::make_pair(id, user));
}

// ajouter un utilisateur à la liste des bannis du channel:
void	Channel::addBan(int id, User user){
	this->_banList.insert(std::make_pair(id, user));
}

// ajouter un utilisateur existant sur le serveur à rejoindre le channel:
void	Channel::addInvite(int id, User user){
	this->_inviteList.insert(std::make_pair(id, user));
}


/*	   DEFINIR / MODIFIER DES PROPRIETES DU CHANNEL    */
/*=====================================================*/

// ajouter ou modifier un topic:
void	Channel::setTopic(std::string topic){
	this->_topic = topic;
}

// ajouter un nombre maximum d'utilisateurs:
void	Channel::setMaxUsers(int maxUsers){
	this->_maxUsers = maxUsers;
}

//activer un mode (forme binaire):
void	Channel::addMode(int to_add){
	this->_chanModes |= to_add;
	setStatus();
}

//désactiver un mode (forme binaire):
void	Channel::rmvMode(int to_rmv){
	this->_chanModes |= to_rmv;
	setStatus();
}

//convertir les modes du channel sous forme de string:
void	Channel::setStatus(){
	this->_chanStatus = "";

	if (this->_chanModes & INVITE_MODE)
		this->_chanStatus += 'i';
	if (this->_chanModes & MODARATE_MODE)
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
