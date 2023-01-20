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
	INVISIBLE_MODE					= 1,	 // 0000 0001   i invisible     1 si l'utilisateur est en mode invisible. Il n'apparait pas du tout dans le /WHO et /NAMES
	AWAY_MODE						= 2,     // 0000 0010   a away			1 si l'utilisateur est déclaré away, si un user envoie un message il est averti de l'absence.
	OPERATOR_MODE					= 4,	 // 0000 0100   o operator		1 si l'utilisateur est opérateur du serveur IRC il peut KILL.
	RESTRICTED_MODE					= 8,	 // 0000 1000   r restricted    1 si PAS CLAIR
	WALLOPS_MODE					= 16,	 // 0001 0000   w wallops		1 si PAS CLAIR envoie de message a tous les operateurs. 
}; 

// ajouter la liste des channels sur lesquels il est connecté?

class	User
{
	private:

		int			_id;
		std::string	_username;
		std::string	_nickname;
		std::string _hostname;
		std::string _realname;

		char		_userModes;
		std::string _userStatus;


	public:

		// CONSTRUCTOR / DESTRUCTOR
		User(std::string username, std::string nickname);
		~User(void);

		// SETTER
		void		setNickname(std::string new_nickname);
		void		setUserModes(char userModes); // modes de l'user sous format numérique
		void		setUserStatus(); // modes de l'user sous forme de lettres
		void		addMode(char to_add);
		void		removeMode(char to_rmv);
		// GETTER
		int			getUserID() const;
		std::string	getUsername() const;
		std::string	getNickname() const;
		std::string getHostname() const;
		std::string getRealname() const;
		char		getUserModes() const;
		std::string	getUserStatus() const;
};

#endif
