/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:37:53 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/27 00:47:40 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "./Include.hpp"
#include "./Server.hpp"

class	command
{
	private:

		std::vector<std::string>	channels;
		std::vector<std::string>	nick;
		std::vector<std::string>	server;
		std::vector<std::string>	message;
		int							client_fd;

	public:

		command();
		~command();
		command(command const &src);

		std::vector<std::string> getchannels();
    	std::vector<std::string> getnickname();
    	std::vector<std::string> getserver();
    	std::vector<std::string> getmessage();
		int						 getClientSfd();

		int						get_size_channels();
		int						get_size_nick();
		int						get_size_server();
		int						get_size_message();

		void					 add_channels(std::string channel);
		void					 add_nick(std::string nick);
		void					 add_server(std::string server);
		void					 add_message(std::string message);
        void					 add_client_fd(int client_fd);


		void					 print_channels();
		void					 print_nick();
		void					 print_server();
		void					 print_message();
		void					 print_all();
};

#endif
