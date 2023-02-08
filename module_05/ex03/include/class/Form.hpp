/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/07 11:39:16 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form
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

	class ExecutionNotPossible : public std::exception
	{
		public :

		static void	print_error(void);
	};

	Form(std::string name, int sign_grade, int exec_grade);
	Form(const Form &src);
	virtual ~Form(void);

	Form	&operator = (const Form &right);
	const std::string	get_name(void) const;
	bool				get_sign(void) const;
	int					get_sign_grade(void) const;
	int					get_exec_grade(void) const;
	int					beSigned(class Bureaucrat &arg);
	void				execute(Bureaucrat const & executor) const;
	virtual void		action(void) = 0;

protected:

private:

	const std::string	_name;
	bool				_sign;
	const int			_sign_grade;
	const int			_exec_grade;
};

std::ostream	&operator << (std::ostream &left, const Form &right);

#endif
