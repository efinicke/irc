/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:21:42 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/29 08:54:32 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/User.hpp"

/*=====================================================*/
/* 				CONTRUCTOR / DESTRUCTOR				   */
/*=====================================================*/

User::User(int sfd, std::string username, std::string nickname, std::string hostname, std::string realname):\
_sfd(sfd), _username(username), _nickname(nickname), _hostname(hostname), _realname(realname){
	this->_userModes = (char)0;
}
User::User(int sfd, std::string username, std::string nickname, std::string hostname, std::string realname, char userModes):\
_sfd(sfd), _username(username), _nickname(nickname), _hostname(hostname), _realname(realname), _userModes(userModes){
}

User::User(std::string nickname, std::string username, std::string hostname, std::string servername, std::string realname)
{
	this->_nickname = nickname;
	this->_username = username;
	this->_hostname = hostname;
	this->_servername = servername;
	this->_realname = realname;
}

User::~User(void) {
}


/*=====================================================*/
/* 					     SETTER						   */
/*=====================================================*/

void		User::setNickname(std::string nickname){
	this->_nickname = nickname;
}

void		User::setUserModes(char userModes){
	this->_userModes = userModes;
	this->setUserStatus();
}

void		User::setUserStatus(){
	this->_userStatus = "";

	if (this->_userModes & INVISIBLE_MODE)
		this->_userStatus += 'i';
	if (this->_userModes & AWAY_MODE)
		this->_userStatus += 'a';
	if (this->_userModes & OPERATOR_MODE)
		this->_userStatus += 'o';
	if (this->_userModes & RESTRICTED_MODE)
		this->_userStatus += 'r';
	if (this->_userModes & WALLOPS_MODE)
		this->_userStatus += 'w';
	if (this->_userStatus != "")
		this->_userStatus = "+" + this->_userStatus;
}

//activer un mode (forme binaire):
void		User::addMode(char to_add){
	this->_userModes |= to_add;
	this->setUserStatus();
}

//désactiver un mode (forme binaire):
void		User::removeMode(char to_rmv){
	this->_userModes |= to_rmv;
	this->setUserStatus();
}

void		User::addChannel(std::string name){
	this->_channels.push_back(name);
}


// enlever un channel de la liste des channels actifs du user: 
int			User::removeChannel(std::string name){
	if (this->findChannel(name)){	
		this->_channels.erase(std::remove(this->_channels.begin(), this->_channels.end(), name), this->_channels.end());
		return (1);
	}
	return (0);
}

/*=====================================================*/
/* 					     GETTER						   */
/*=====================================================*/

std::string			User::getUserSfd() const{
	std::stringstream ss;
	ss << this->_sfd;
	std::string str = ss.str();
	return (str);
}

int			User::getUserSfdN() const{
	return (this->_sfd);
}

std::string	User::getUsername() const{
	return (this->_username);
}

std::string	User::getNickname() const{
	return (this->_nickname);
}

std::string	User::getHostname() const{
	return (this->_hostname);
}

std::string	User::getRealname() const{
	return (this->_realname);
}

char		User::getUserModes() const{
	return (this->_userModes);
}

std::string	User::getUserStatus() const{
	return (this->_userStatus);
}

std::vector<std::string>	User::getChannels() const{
	return (this->_channels);
}

void						User::printChannels() const{
	
	std::vector<std::string>::iterator it;

	for (it = this->getChannels().begin(); it != this->getChannels().end(); it++){
		std::cout << "[" << *it << "]" << std::endl;
	}
}

int							User::findChannel(std::string name) const{
	std::vector<std::string>::iterator it;

		for (it = this->getChannels().begin(); it != this->getChannels().end(); it++){
			if ((*it) == name)
				return (1);
	}
	return (0);
}