/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:58:13 by lyeh              #+#    #+#             */
/*   Updated: 2024/04/23 15:35:19 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string old_str, std::string new_str)
    : _input_fp(filename), _output_fp(filename + ".replace"), _old_str(old_str), _new_str(new_str)
{
    std::ifstream file(this->_input_fp.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: File not found" << std::endl;
        this->_input_fp = "";
        return;
    }

    std::string line;
    while (std::getline(file, line))
        this->_file_content << line << std::endl;
    file.close();
}

Replacer::~Replacer(void) {}

std::string Replacer::_getInputFileContent(void)
{
    return this->_file_content.str();
}

void Replacer::replace(void)
{
    std::string content = this->_getInputFileContent();
    size_t pos = 0;

    if (this->_file_content.str().empty())
    {
        std::cout << "Error: File is empty" << std::endl;
        return;
    }
    if (this->_old_str.empty() && this->_new_str.empty())
    {
        std::cout << "Error: Old and New string is empty" << std::endl;
        return;
    }
    if (this->_old_str.empty())
    {
        std::cout << "Error: Old string is empty" << std::endl;
        return;
    }

    while ((pos = content.find(this->_old_str, pos)) != std::string::npos)
    {
        std::string first_part = content.substr(0, pos);
        std::string second_part = content.substr(pos + this->_old_str.length());
        content = first_part + this->_new_str + second_part;
        pos += this->_new_str.length();
    }

    std::ofstream file(this->_output_fp.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: File could not be created" << std::endl;
        return;
    }
    file << content;
    file.close();
}
