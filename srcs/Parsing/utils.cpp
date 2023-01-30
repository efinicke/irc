/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 02:04:33 by ejahan            #+#    #+#             */
/*   Updated: 2023/01/25 02:33:11 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Parsing.hpp"

int	search_channel(std::string nick, std::vector<std::string> channels)
{
	std::vector<std::string>::iterator	it = channels.begin();
	std::vector<std::string>::iterator	ite = channels.end();

	while (it != ite)
	{
		if (*it == nick)
			return (1);
		it++;
	}

	return (0);
}

void	print_vector(std::vector<std::string> vect)
{
	std::vector<std::string>::iterator	it = vect.begin();
	std::vector<std::string>::iterator	ite = vect.end();

	std::cout << RED << "_________________________" << RESET << std::endl;
	while (it != ite)
	{
		std::cout << "[" << *it << "]" << std::endl;
		it++;
	}
}

std::string	join_message(std::string buffer, int i, std::vector<std::string> vect)
{
	(void)vect;
	std::string	trim = buffer;
	std::istringstream iss(trim);
	std::string token;

	while (i > 0 && std::getline(iss, token, ' '))
		i--;
	std::getline(iss, token, '\r');
	trim.erase(trim.find_first_not_of(" "));

	size_t j = 0;
	while (token[j] == ' ')
		j++;
	token = token.substr(j);

	return (token);
}

int	check_channel(int i, std::vector<std::string> vect)
{
	std::vector<std::string>::iterator	it = (vect.begin() + i);
	std::string	str = *it;

	if (str[0] != '#')
		return (1);
	return (0);
}
