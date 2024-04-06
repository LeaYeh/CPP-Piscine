/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:59:27 by lyeh              #+#    #+#             */
/*   Updated: 2024/04/05 21:34:26 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
    int         _index;
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;

public:
    Contact(void);
    ~Contact(void);

    bool is_empty(const std::string s);
    void set_index(const int index);
    void set_first_name(const std::string first_name);
    void set_last_name(const std::string last_name);
    void set_nickname(const std::string nickname);
    void set_phone_number(const std::string phone_number);
    void set_darkest_secret(const std::string darkest_secret);
    int get_index(void) const;
    std::string get_first_name(void) const;
    std::string get_last_name(void) const;
    std::string get_nickname(void) const;
    std::string get_phone_number(void) const;
    std::string get_darkest_secret(void) const;
};

#endif