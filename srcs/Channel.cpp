/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:21:40 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/09 05:03:54 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Channel.hpp"

/*=====================================================*/
/* 				CONTRUCTOR / DESTRUCTOR				   */
/*=====================================================*/

Channel::Channel(std::string name) : _name(name) {}

Channel::~Channel(void) {}



/*=====================================================*/
/* 					     GETTER						   */
/*=====================================================*/

std::string	Channel::GetName(void)
{
	return (this->_name);
}

std::map<int, User>	Channel::GetUsers(void)
{
	return (this->_usersList);
}

std::map<int, User>	Channel::GetOperators(void)
{
	return (this->_operatorsList);
}

std::map<int, User>	Channel::GetBan(void)
{
	return (this->_banList);
}



/*=====================================================*/
/*		   AJOUTER UN USER / OPERATOR / USER BAN	   */
/*=====================================================*/

void	Channel::AddUser(int id, User user)
{
	this->_usersList.insert(std::make_pair(id, user));
}

void	Channel::AddOperator(int id, User user)
{
	this->_operatorsList.insert(std::make_pair(id, user));
}

void	Channel::AddBan(int id, User user)
{
	this->_banList.insert(std::make_pair(id, user));
}
