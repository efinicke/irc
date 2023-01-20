/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:21:42 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/09 05:03:48 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/User.hpp"

/*=====================================================*/
/* 				CONTRUCTOR / DESTRUCTOR				   */
/*=====================================================*/

User::User(std::string username, std::string nickname) : _username(username), _nickname(nickname) {}

User::~User(void) {}



/*=====================================================*/
/* 					     SETTER						   */
/*=====================================================*/

void		User::setNickname(std::string new_nickname){
	this->_nickname = new_nickname;
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

/*=====================================================*/
/* 					     GETTER						   */
/*=====================================================*/

std::string	User::getUsername(void) const{
	return (this->_username);
}

std::string	User::getNickname(void) const{
	return (this->_nickname);
}

std::string	User::getHostname(void) const{
	return (this->_hostname);
}

std::string	User::getRealname(void) const{
	return (this->_realname);
}

char		User::getUserModes(void) const{
	return (this->_userModes);
}

std::string	User::getUserStatus(void) const{
	return (this->_userStatus);
}
