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
