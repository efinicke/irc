/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:21:35 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/30 03:28:36 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
#define USER_HPP

#include "./Include.hpp"

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

		int							_sfd;
		std::string					_username;
		std::string					_nickname;
		std::string 				_hostname;
		std::string 				_realname;
		std::string					_servername;
		
		std::vector<std::string>	_channels;

		char						_userModes;
		std::string 				_userStatus;


	public:

		// CONSTRUCTOR / DESTRUCTOR
		User(int sfd, std::string username, std::string nickname, std::string hostname, std::string realname);
		User(int sfd, std::string username, std::string nickname, std::string hostname, std::string realname, char userModes);
		User(std::string nickname, std::string username, std::string hostname, std::string servername, std::string realname);
		~User(void);

		// SETTER
		void			setNickname(std::string nickname);
		void			setUserModes(char userModes); // modes de l'user sous format numérique
		void			setUserStatus(); // modes de l'user sous forme de lettres

		void			addMode(char to_add);
		void			removeMode(char to_rmv);
		
		void			addChannel(std::string name);
		int				removeChannel(std::string name);
		
		// GETTER
		std::string					getUserSfd() const; //renvoie le sfd du User sous forme de string
		int							getUserSfdN() const; //renvoie le sfd sous forme d'entier
		std::string					getUsername() const;
		std::string					getNickname() const;
		std::string 				getHostname() const;
		std::string 				getRealname() const;
		char						getUserModes() const;
		std::string					getUserStatus() const;
		
		std::vector<std::string>	getChannels() const;
		int							findChannel(std::string name) const;
		void						printChannels() const;
		
		
		
};

// juste pour tester -> a supprimer plus tard
std::ostream    &operator<<(std::ostream &out, User const &user);

#endif
