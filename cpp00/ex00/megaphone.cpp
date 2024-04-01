/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:35:09 by lyeh              #+#    #+#             */
/*   Updated: 2024/04/01 11:10:00 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

void	print_upper_string(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << str;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::for_each(argv + 1, argv + argc, print_upper_string);
	std::cout << std::endl;
	return (0);
}
