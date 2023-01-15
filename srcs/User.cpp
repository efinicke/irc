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

void		User::SetNickname(std::string new_nickname)
{
	this->_nickname = new_nickname;
}



/*=====================================================*/
/* 					     GETTER						   */
/*=====================================================*/

std::string	User::GetUsername(void)
{
	return (this->_username);
}

std::string	User::GetNickname(void)
{
	return (this->_nickname);
}
