/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:44:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/11 13:31:43 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class PhoneBook
{

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	add_contact(void);
	void	print_contact(void);
	void	choice_index(void);
	void	print_one_contact(int index);

private:

	std::list<Contact> list_contact;
};

#endif
