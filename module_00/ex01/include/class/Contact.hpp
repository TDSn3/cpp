/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:44:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/11 14:04:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{

public:

	Contact(void);
	~Contact(void);

	void	add_contact(
				std::string first_name,
				std::string last_name,
				std::string nickname,
				std::string phone_number,
				std::string darkest_secret);
	void	print_content(int index);
	void	print_all(void);

private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

};

#endif
