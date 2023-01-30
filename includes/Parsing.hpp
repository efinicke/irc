/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 06:25:38 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/27 01:03:48 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
#define PARSING_HPP

#include "./Include.hpp"
#include "./Server.hpp"
#include "./Command.hpp"



// #define ERR_UNKNOWNCOMMAND(command) (command + " :Unknown command\r\n") //421
// #define ERR_NEEDMOREPARAMS(localhost, key) (":" + localhost + " 461 " + key + " :Not enough parameters\r\n")


//////////////////////////////////////////////////////////////////////////////////
//                                   PARSING                                    //
//////////////////////////////////////////////////////////////////////////////////

void	parsing(char *buffer, Server *ircServ, int client_fd);


//////////////////////////////////////////////////////////////////////////////////
//                                   COMMANDS                                   //
//////////////////////////////////////////////////////////////////////////////////

void	invite_pars(std::vector<std::string> vect, Server *ircServ, int client_fd);
void	join_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd);
void	kick_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd);
void	kill_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd);
void	list_pars(std::vector<std::string> vect, Server *ircServ, int client_fd);
void	motd_pars(std::vector<std::string> vect, Server *ircServ, int client_fd);
void	names_pars(std::vector<std::string> vect, Server *ircServ, int client_fd);
void	nick_pars(std::vector<std::string> vect, Server *ircServ, int client_fd);
void	notice_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd);
void	oper_pars(std::vector<std::string> vect, Server *ircServ, int client_fd);
void	part_pars(std::vector<std::string> vect, Server *ircServ, int client_fd);
void	pass_pars(std::vector<std::string> vect, Server *ircServ, int client_fd);
void	ping_pars(std::vector<std::string> vect, Server *ircServ, int client_fd);
void	privmsg_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd);
void	quit_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd);
void	topic_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd);
// void	user_pars(std::vector<std::string> vect, Server *ircServ, int client_fd);
void	user_pars(std::string buffer, std::vector<std::string> vect, Server *ircServ, int client_fd);

//////////////////////////////////////////////////////////////////////////////////
//                                     UTILS                                    //
//////////////////////////////////////////////////////////////////////////////////

void	print_vector(std::vector<std::string> vect);
int	search_channel(std::string nick, std::vector<std::string> channels);
std::string	join_message(std::string buffer, int i, std::vector<std::string> vect);
int	check_channel(int i, std::vector<std::string> vect);


//////////////////////////////////////////////////////////////////////////////////
//                                     commands                                 //
//////////////////////////////////////////////////////////////////////////////////

void	quit_cmd(command *cmd, Server *ircServ);
void	pass_cmd(command *cmd, Server *ircServ);
void	user_cmd(std::string nickname, std::string hostname, command *cmd, Server *ircServ);


#endif
