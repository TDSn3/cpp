/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:55:25 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/08 16:19:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:

	class FileNotOpen : public std::exception
	{
		public :

		static void	print_error(void);
	};


	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm	&operator = (const ShrubberyCreationForm &right);
	std::string	get_target() const;
	void	action(void);

protected:

private:

	const std::string	_target;

};

#endif
