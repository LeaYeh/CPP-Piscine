/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:35:09 by lyeh              #+#    #+#             */
/*   Updated: 2024/04/11 15:58:37 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void print_upper_string(std::string str)
{
    // std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    // for (std::string::iterator it = str.begin(); it != str.end(); it++)
    //     *it = std::toupper(*it);
    for (int i = 0; i < str.length(); i++)
        str[i] = std::toupper(str[i]);
    std::cout << str;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    // Transform each command-line argument to uppercase and print with lambda function
    // std::for_each(argv + 1, argv + argc, [](char* arg) {
    //     std::string str(arg);
    //     std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    //     std::cout << str;
    // });
    // std::for_each(argv + 1, argv + argc, print_upper_string);
    for (int i = 1; i < argc; i++)
    {
        if (i > 1)
            std::cout << " ";
        print_upper_string(argv[i]);
    }
    std::cout << std::endl;
    return (0);
}
