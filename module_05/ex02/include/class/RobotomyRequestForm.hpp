/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:38:18 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/08 17:39:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:

	class FileNotOpen : public std::exception
	{
		public :

		static void	print_error(void);
	};


	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm(void);

	RobotomyRequestForm	&operator = (const RobotomyRequestForm &right);
	std::string	get_target() const;
	void	action(void);

protected:

private:

	const std::string	_target;

};

#endif
