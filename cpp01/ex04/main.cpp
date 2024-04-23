/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:59:05 by lyeh              #+#    #+#             */
/*   Updated: 2024/04/23 13:35:39 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        std::cout << "Usage: ./replace filename old_str new_str" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string old_str = argv[2];
    std::string new_str = argv[3];
    Replacer replacer(filename, old_str, new_str);

    replacer.replace();

    return (0);
}
