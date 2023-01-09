/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:44:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/09 12:15:20 by tda-silv         ###   ########.fr       */
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

	int		size_contact(void);
	Contact	*get_older_contact(void);
	void	add_contact(void);
	void	print_contact(void);

private:

	Contact	instance_contact[8];

};

#endif
