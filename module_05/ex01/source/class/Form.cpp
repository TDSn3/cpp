/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/08 11:32:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name) , _sign_grade(sign_grade) , _exec_grade(exec_grade)
{
	std::cout << "\033[00;02;03m" << "Form : Default constructor called" << "\033[00m" << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw (GradeTooLowException());
	else if (sign_grade > 150 || exec_grade > 150)
		throw (GradeTooHighException());
	this->_sign = 0;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

Form::Form(const Form &src) : _name(src.get_name()) , _sign_grade(src.get_sign_grade()) , _exec_grade(src.get_exec_grade())
{
	std::cout << "\033[32;02;03m" << "Form : Copy constructor called" << "\033[00m" << std::endl;
	(void) src;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Form::~Form(void)
{
	std::cout << "\033[31;01m" << "Form : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

Form		&Form::operator = (const Form &right)
{
	std::cout << "\033[33;02;03m" << "Form : Copy assignment operator called" << "\033[00m" << std::endl;
	(void) right;
	return (*this);
}

/*   OPÉRATEUR EXTERNE   **************************************************** */

std::ostream	&operator << (std::ostream &left, const Form &right)
{
	left << "——————————\n"
	<< right.get_name() << "\n"
	<< right.get_sign() << "\n"
	<< right.get_sign_grade() << "\n"
	<< right.get_exec_grade() << "\n"
	<< "––––––––––";
	return (left);
}

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

const std::string	Form::get_name(void) const
{
	return (this->_name);
}
bool				Form::get_sign(void) const
{
	return (this->_sign);
}
int					Form::get_sign_grade(void) const
{
	return (this->_sign_grade);
}
int					Form::get_exec_grade(void) const
{
	return (this->_exec_grade);
}

int					Form::beSigned(class Bureaucrat &arg)
{
	if (arg.get_grade() <= this->_sign_grade && !this->_sign)
	{
		this->_sign = 1;
		return (0);
	}
	else if (arg.get_grade() <= this->_sign_grade && this->_sign)
	{
		return (1);
	}
	throw (GradeTooLowException());
	return(1);
}

/* static */void	Form::GradeTooHighException::print_error(void)
{
	std::cout << "Grade too high exception!" << std::endl;
}

/* static */void	Form::GradeTooLowException::print_error(void)
{
	std::cout << "Grade too low exception!" << std::endl;
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
