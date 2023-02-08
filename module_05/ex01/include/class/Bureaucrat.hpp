/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/08 14:44:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Bureaucrat
{
public:

	class GradeTooHighException : public std::exception
	{
		public :

		static void	print_error(void);
	};

	class GradeTooLowException : public std::exception
	{
		public :

		static void	print_error(void);
	};

	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat(void);

	Bureaucrat			&operator = (const Bureaucrat &right);
	Bureaucrat			&operator ++ (void);
	Bureaucrat			operator ++ (int useless);
	Bureaucrat			&operator -- (void);
	Bureaucrat			operator -- (int useless);
	const std::string	get_name(void) const;
	int					get_grade(void) const;
	void				signForm(Form &arg);

protected:

private:

	const std::string	_name;
	int 				_grade;
};

std::ostream			&operator << (std::ostream &left, const Bureaucrat &right);

#endif
