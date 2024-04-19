/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:17:53 by lyeh              #+#    #+#             */
/*   Updated: 2024/04/19 11:23:47 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

bool Contact::is_empty(const std::string s)
{
    return s.length() == 0;
}

void Contact::set_index(const int index)
{
    this->_index = index;
}
void Contact::set_first_name(const std::string first_name)
{
    if (this->is_empty(first_name))
        throw std::invalid_argument("First name cannot be empty");
    this->_first_name = first_name;
}

void Contact::set_last_name(const std::string last_name)
{
    if (this->is_empty(last_name))
        throw std::invalid_argument("Last name cannot be empty");
    this->_last_name = last_name;
}

void Contact::set_nickname(const std::string nickname)
{
    if (this->is_empty(nickname))
        throw std::invalid_argument("Nickname cannot be empty");
    this->_nickname = nickname;
}

void Contact::set_phone_number(const std::string phone_number)
{
    if (this->is_empty(phone_number))
        throw std::invalid_argument("Phone number cannot be empty");
    this->_phone_number = phone_number;
}

void Contact::set_darkest_secret(const std::string darkest_secret)
{
    if (this->is_empty(darkest_secret))
        throw std::invalid_argument("Darkest secret cannot be empty");
    this->_darkest_secret = darkest_secret;
}

int Contact::get_index(void) const
{
    return this->_index;
}

std::string Contact::get_first_name(void) const
{
    return this->_first_name;
}

std::string Contact::get_last_name(void) const
{
    return this->_last_name;
}

std::string Contact::get_nickname(void) const
{
    return this->_nickname;
}

std::string Contact::get_phone_number(void) const
{
    return this->_phone_number;
}

std::string Contact::get_darkest_secret(void) const
{
    return this->_darkest_secret;
}
