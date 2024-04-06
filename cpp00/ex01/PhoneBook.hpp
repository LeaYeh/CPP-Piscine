/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:14:43 by lyeh              #+#    #+#             */
/*   Updated: 2024/04/06 11:13:32 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstdio>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
private:
    static const int _MAX_CONTACT = 8;
    static const int _MAX_TEXT_LENGTH = 10;
    int _contact_count;
    std::array<Contact, _MAX_CONTACT> _contact_array;

    void _add_contact(const std::string first_name,
                      const std::string last_name,
                      const std::string nickname,
                      const std::string phone_number,
                      const std::string darkest_secret);
    void _print_contact(const Contact contact);
    void _print_contact_list(void);
    void _add_operation(void);
    bool _search_operation(void);
    int _handle_input_text(const std::string input);
    std::string _format_cell_text(const std::string& text);
    std::string _format_row_info(const Contact& contact);

public:
    PhoneBook(void);
    ~PhoneBook(void);

    void run(void);
};

#endif
