/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:14:43 by lyeh              #+#    #+#             */
/*   Updated: 2024/04/02 17:20:56 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include <iomanip>
#include <algorithm>
#include "Contact.class.hpp"

class PhoneBook
{
private:
    static const int _MAX_CONTACT = 8;
    static const int _MAX_TEXT_LENGTH = 10;
    int _contact_count;
    std::array<Contact, _MAX_CONTACT> _contact_array;

    void _add_operation(void);
    void _search_operation(void);
    void _print_contact(Contact contact);
    void _print_contact_list(void);

public:
    PhoneBook(void);
    ~PhoneBook(void);

    void run(void);

    void add_contact(std::string first_name,
                     std::string last_name,
                     std::string nickname,
                     std::string phone_number,
                     std::string darkest_secret);
    void search_contact(void);
};

#endif
