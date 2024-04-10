/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:15:38 by lyeh              #+#    #+#             */
/*   Updated: 2024/04/10 16:12:54 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _contact_count(0){};

PhoneBook::~PhoneBook(void){};

void PhoneBook::_add_operation(void)
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "Enter first name: ";
    std::cin >> first_name;
    std::cout << "Enter last name: ";
    std::cin >> last_name;
    std::cout << "Enter nickname: ";
    std::cin >> nickname;
    std::cout << "Enter phone number: ";
    std::cin >> phone_number;
    std::cout << "Enter darkest secret: ";
    std::cin >> darkest_secret;

    this->_add_contact(first_name, last_name, nickname, phone_number, darkest_secret);
}

/*
1-byte sequences: 0xxxxxxx (ASCII characters)
2-byte sequences: 110xxxxx 10xxxxxx
3-byte sequences: 1110xxxx 10xxxxxx 10xxxxxx
4-byte sequences: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

0xC0:             11000000
0x80:             10000000
*/
int PhoneBook::_get_visual_width(const std::string& text)
{
    int width = 0;

    for (std::string::const_iterator it = text.begin(); it != text.end(); ++it)
    {
        unsigned char c = *it;
        if ((c & 0xC0) != 0x80) // If the byte is not a continuation byte
            width++;
    }
    return width;
}

std::string PhoneBook::_format_cell_text(const std::string &text)
{
    int len = 0;
    int byte_pos = 0;

    for (std::string::const_iterator it = text.begin(); it != text.end(); ++it)
    {
        unsigned char c = *it;
        if ((c & 0xC0) != 0x80) // If the byte is not a continuation byte
        {
            if (len == _MAX_TEXT_LENGTH - 1)
            {
                if (byte_pos < text.length() - 1)
                    return text.substr(0, byte_pos) + ".";
                return text.substr(0, byte_pos);
            }
            len++;
        }
        byte_pos++;
    }
    // if (text.length() > _MAX_TEXT_LENGTH)
    //     return text.substr(0, _MAX_TEXT_LENGTH - 1) + ".";
    return text;
}

std::string PhoneBook::_format_row_info(const Contact &contact)
{
    std::stringstream ss;
    std::string first_name = this->_format_cell_text(contact.get_first_name());
    std::string last_name = this->_format_cell_text(contact.get_last_name());
    std::string nickname = this->_format_cell_text(contact.get_nickname());
    int extend_width_fn = first_name.length() - this->_get_visual_width(first_name);
    int extend_width_ln = last_name.length() - this->_get_visual_width(last_name);
    int extend_width_nn = nickname.length() - this->_get_visual_width(nickname);

    ss << std::setw(_MAX_TEXT_LENGTH) << contact.get_index() << "|"
       << std::setw(_MAX_TEXT_LENGTH + extend_width_fn) << first_name << "|"
       << std::setw(_MAX_TEXT_LENGTH + extend_width_ln) << last_name << "|"
       << std::setw(_MAX_TEXT_LENGTH + extend_width_nn) << nickname;

    return ss.str();
}

void PhoneBook::_print_contact_list(void)
{
    std::cout << std::right;
    std::cout << std::setw(_MAX_TEXT_LENGTH) << "Index"
              << "|" << std::setw(_MAX_TEXT_LENGTH) << "First Name"
              << "|" << std::setw(_MAX_TEXT_LENGTH) << "Last Name"
              << "|" << std::setw(_MAX_TEXT_LENGTH) << "Nickname" << std::endl;
    for (int i = 0; i < _MAX_CONTACT && i < this->_contact_count; ++i)
        std::cout << this->_format_row_info(this->_contact_array[i]) << std::endl;
    std::cout << std::endl;
}

void PhoneBook::_print_contact(Contact contact)
{
    std::cout << std::endl;
    std::cout << "First name: " << contact.get_first_name() << std::endl;
    std::cout << "Last name: " << contact.get_last_name() << std::endl;
    std::cout << "Nickname: " << contact.get_nickname() << std::endl;
    std::cout << "Phone number: " << contact.get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << contact.get_darkest_secret() << std::endl;
    std::cout << std::endl;
}

int PhoneBook::_handle_input_text(const std::string input)
{
    int index;

    std::stringstream ss(input);
    if (!(ss >> index))
        index = -1;
    return index;
}

bool PhoneBook::_search_operation(void)
{
    std::string input;
    int index = -1;

    if (this->_contact_count == 0)
    {
        std::cout << "Phone book is empty" << std::endl
                  << std::endl;
        return true;
    }
    this->_print_contact_list();
    while (true)
    {
        std::cout << "Enter the index of the contact: ";
        if (!(std::cin >> input))
            return (std::cin.clear(), std::clearerr(stdin), std::cout << std::endl, true);
        index = this->_handle_input_text(input);
        if (index < 0 || (index >= this->_contact_count || index >= _MAX_CONTACT))
        {
            std::cout << "Invalid index" << std::endl
                      << std::endl;
            continue;
        }
        break;
    }
    return (this->_print_contact(this->_contact_array[index]), true);
}

void PhoneBook::run(void)
{
    std::string command;
    int contact_index;

    while (true)
    {
        std::cout << "Enter a command: ";
        if (!(std::cin >> command))
        {
            std::cin.clear();
            std::clearerr(stdin);
            std::cout << std::endl;
            break;
        }
        else if (command == "ADD")
            this->_add_operation();
        else if (command == "SEARCH")
        {
            if (!this->_search_operation())
                break;
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command" << std::endl
                      << std::endl;
    }
    std::cout << "\nLogout of the service." << std::endl;
}

void PhoneBook::_add_contact(const std::string first_name,
                             const std::string last_name,
                             const std::string nickname,
                             const std::string phone_number,
                             const std::string darkest_secret)
{
    int index = this->_contact_count % _MAX_CONTACT;

    if (this->_contact_count >= _MAX_CONTACT)
        std::cout << "Phone book is full, the new contact will replace the " << index + 1 << " contact" << std::endl;
    this->_contact_array[index].set_index(index);
    this->_contact_array[index].set_first_name(first_name);
    this->_contact_array[index].set_last_name(last_name);
    this->_contact_array[index].set_nickname(nickname);
    this->_contact_array[index].set_phone_number(phone_number);
    this->_contact_array[index].set_darkest_secret(darkest_secret);
    std::cout << "Contact added at [" << index + 1 << "/" << _MAX_CONTACT << "]" << std::endl;
    std::cout << "" << std::endl;
    this->_contact_count++;
}
