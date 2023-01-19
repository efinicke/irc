/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:21:35 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/09 05:01:19 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
#define USER_HPP

#include "./include.hpp"

enum	userModes
{
	INVITE_MODE     				=  1,    // 0000 0001,  i invite        1 si le chan est en mode invite only
	MODARATE_MODE   				=  2,    // 0000 0010,  m moderated     1 si le mode est modéré, CAD que seuls les op et les users autorisés à parler (voiced, mode +v) pouvent parler sur le chan
	PRIVATE_MODE    				=  4,    // 0000 0100,  p private       1 si le channel est en mode privé (le topic ne doit pas etre affiché)
	KEY_MODE        				=  8,    // 0000 1000,  k key           1 si un password a été assigné au channel
	SECRET_MODE     				=  16,   // 0001 0000,  s secret        1 si le le mode secret du chan est activé (/MODE +)
	LIMITED_MODE    				=  32,   // 0010 0000,  l users limit   1 si nombre limite d'utilisateurs est défini(/MODE +l [nbr])
	TOPIC_MODE      				=  64,   // 0100 0000,  t topic		    1 si seuls les ChannelOperator peuvent changer le topic
	NO_OUTSIDE_PRVMSG_MODE          =  128   // 1000 0000,  n outside pvmsg 1 si les messages privés sont interdits en dehors du chan
}; 

class	User
{
	private:
	
		std::string	_username;
		std::string	_nickname;
		std::string _hostname;
		std::string _realname;
		

	public:

		// CONSTRUCTOR / DESTRUCTOR
		User(std::string username, std::string nickname);
		~User(void);

		// SETTER
		void		SetNickname(std::string new_nickname);

		// GETTER
		std::string	GetUsername(void);
		std::string	GetNickname(void);

};

#endif
