/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:58:13 by lyeh              #+#    #+#             */
/*   Updated: 2024/04/08 16:43:47 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string old_str, std::string new_str)
    : _input_fp(filename), _old_str(old_str), _new_str(new_str), _output_fp(filename + ".replace")
{
    std::ifstream file(this->_input_fp);
    if (!file.is_open())
    {
        std::cout << "Error: File not found" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
        this->_file_content << line << std::endl;
    file.close();
}

Replacer::~Replacer(void) {};

std::string Replacer::_getInputFileContent(void)
{
    return this->_file_content.str();
}

void Replacer::replace(void)
{
    std::string content = this->_getInputFileContent();
    size_t pos = 0;

    while ((pos = content.find(this->_old_str, pos)) != std::string::npos)
    {
        content.replace(pos, this->_old_str.length(), this->_new_str);
        pos += this->_new_str.length();
    }

    std::ofstream file(this->_output_fp);
    if (!file.is_open())
    {
        std::cout << "Error: File could not be created" << std::endl;
        return;
    }
    file << content;
    file.close();
}
