/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:21:37 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/09 05:00:56 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "./include.hpp"
#include "./User.hpp"


class	Channel
{
	private:

		std::map<int, User>		_usersList; // liste des utilisateurs connectés au channel
		std::map<int, User>		_operatorsList; // liste des opérateurs connectés sur le channel
		//std::map<int, User>		_voicedList; // liste des users autorisés à parler sur le chan, en dehors des opérateurs
		std::map<int, User>		_banList; // liste des users bannis.
		std::map<int, User>		_inviteList; // liste des users invités dans le chan.

		
		//std::string				_password; // mot de passe du channel
		std::string				_name; // nom du channel
		//std::string				_topic; // sujet du channel
		//int						_maxUsers; // nombre maximum d'utilisateurs autorisés à se connecter sur ce channel.

		//bool					_hasTopic; // 1 si il existe un topic. Il sera affiché avec la commande /LIST s'il existe.
		//bool					_iMode; // invite        1 si le chan est en mode invite only.
		//bool					_mMode; // moderated     1 si le mode est modéré, CAD que seuls les op et les users autorisés à parler (voiced, mode +v) pouvent parler sur le chan.
		//bool					_pMode; // private       1 si le channel est en mode privé (le topic ne doit pas etre affiché)
		//bool					_kMode; // key           1 si un password a été assigné au channel.
		//bool					_sMode; // secret        1 si le le mode secret du chan est activé (/MODE +).
		//bool					_lMode; // users limit   1 si nombre limite d'utilisateurs est défini(/MODE +l [nbr]).
		//bool					_tMode; // topic		 1 si seuls les ChannelOperator peuvent changer le topic.
		//bool					_nMode; // outside pvmsg 1 si les messages privés sont interdits en dehors du chan
		// configuration par défaut : 

	public:

		// CONTRUCTOR / DESTRUCTOR
		Channel(std::string name);
		//Channel(std::string name, std::map<int, User> usersList);
		Channel();
		~Channel(void);

		// GETTER
		std::string			GetName(void);
		std::map<int, User>	GetUsers(void);
		std::map<int, User>	GetOperators(void);
		std::map<int, User>	GetBan(void);

		// AJOUTER UN USER / OPERATOR / USER BAN
		void	AddUser(int id, User user);
		void	AddOperator(int id, User user);
		void	AddBan(int id, User user);
};

#endif
