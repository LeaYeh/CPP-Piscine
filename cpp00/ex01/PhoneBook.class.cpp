/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:15:38 by lyeh              #+#    #+#             */
/*   Updated: 2024/04/02 17:25:28 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _contact_count(0){};

PhoneBook::~PhoneBook(void) = default;

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

    this->add_contact(first_name, last_name, nickname, phone_number, darkest_secret);
}

void PhoneBook::_print_contact_list(void)
{
    auto _format_cell_text = [](const std::string &text) -> std::string
    {
        if (text.length() > 10)
            return text.substr(0, 9) + ".";
        return text;
    };
    std::cout << std::right;
    std::cout << std::setw(10) << "Index"
              << "|"
              << std::setw(10) << "First Name"
              << "|"
              << std::setw(10) << "Last Name"
              << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::for_each(this->_contact_array.begin(),
                  this->_contact_array.begin() + this->_contact_count,
                  [_format_cell_text](Contact &contact)
                  { std::cout << std::setw(10) << contact.get_index() << "|"
                              << std::setw(10) << _format_cell_text(contact.get_first_name()) << "|"
                              << std::setw(10) << _format_cell_text(contact.get_last_name()) << "|"
                              << std::setw(10) << _format_cell_text(contact.get_nickname()) << std::endl; });
}

void PhoneBook::_print_contact(Contact contact)
{
    std::cout << "First name: " << contact.get_first_name() << std::endl;
    std::cout << "Last name: " << contact.get_last_name() << std::endl;
    std::cout << "Nickname: " << contact.get_nickname() << std::endl;
    std::cout << "Phone number: " << contact.get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << contact.get_darkest_secret() << std::endl;
}

void PhoneBook::_search_operation(void)
{
    int index;

    if (this->_contact_count == 0)
    {
        std::cout << "Phone book is empty" << std::endl;
        return;
    }
    this->_print_contact_list();
    std::cout << "Enter the index of the contact: ";
    std::cin >> index;
    if (index < 0 || index >= this->_MAX_CONTACT)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    std::cout << "" << std::endl;
    this->_print_contact(this->_contact_array[index]);
}

void PhoneBook::run(void)
{
    std::string command;

    while (true)
    {
        std::cout << "Enter a command: ";
        std::cin >> command;
        if (command == "ADD")
            this->_add_operation();
        else if (command == "SEARCH")
            this->_search_operation();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command" << std::endl;
    }
    std::cout << "Logout of the service." << std::endl;
}

void PhoneBook::add_contact(std::string first_name,
                            std::string last_name,
                            std::string nickname,
                            std::string phone_number,
                            std::string darkest_secret)
{
    int index = this->_contact_count % this->_MAX_CONTACT;

    if (this->_contact_count >= 8)
        std::cout << "Phone book is full, the new contact will replace the " << index << " contact" << std::endl;
    this->_contact_array[index].set_index(index);
    this->_contact_array[index].set_first_name(first_name);
    this->_contact_array[index].set_last_name(last_name);
    this->_contact_array[index].set_nickname(nickname);
    this->_contact_array[index].set_phone_number(phone_number);
    this->_contact_array[index].set_darkest_secret(darkest_secret);
    std::cout << "Contact added [" << index + 1 << "/" << this->_MAX_CONTACT << "]" << std::endl;
    this->_contact_count++;
}
