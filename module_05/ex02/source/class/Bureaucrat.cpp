/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/10 10:58:00 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "\033[00;02;03m" << "Bureaucrat : Default constructor called" << "\033[00m" << std::endl;
	if (grade < 1)
		throw (GradeTooLowException());
	else if (grade > 150)
		throw (GradeTooHighException());
	this->_grade = grade;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "\033[32;02;03m" << "Bureaucrat : Copy constructor called" << "\033[00m" << std::endl;
	(void) src;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "\033[31;01m" << "Bureaucrat : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

Bureaucrat		&Bureaucrat::operator = (const Bureaucrat &right)
{
	std::cout << "\033[33;02;03m" << "Bureaucrat : Copy assignment operator called" << "\033[00m" << std::endl;
	_grade = right._grade;
	return (*this);
}

Bureaucrat		&Bureaucrat::operator ++ (void)
{
	if (this->_grade - 1 < 1)
		throw (GradeTooLowException());
	--(this->_grade);
	return (*this);
}

Bureaucrat		Bureaucrat::operator ++ (int useless)
{
	Bureaucrat	return_Bureaucrat(this->get_name(), 150);

	return_Bureaucrat = *this;
	(void) useless;
	if (this->_grade - 1 < 1)
		throw (GradeTooLowException());
	(this->_grade)--;
	return (return_Bureaucrat);
}

Bureaucrat		&Bureaucrat::operator -- (void)
{
	if (this->_grade + 1 > 150)
		throw (GradeTooHighException());
	++(this->_grade);
	return (*this);
}

Bureaucrat		Bureaucrat::operator -- (int useless)
{
	Bureaucrat	return_Bureaucrat("pointer", 150);

	(void) useless;
	return_Bureaucrat = *this;
	if (this->_grade + 1 > 150)
		throw (GradeTooHighException());
	(this->_grade)++;
	return (return_Bureaucrat);
}

/*   OPÉRATEUR EXTERNE   **************************************************** */

std::ostream	&operator << (std::ostream &left, const Bureaucrat &right)
{
	left << right.get_name() << ", bureaucrat grade " << right.get_grade() << ".";
	return (left);
}

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

const std::string	Bureaucrat::get_name(void) const
{
	return (this->_name);
}

int					Bureaucrat::get_grade(void) const
{
	return (this->_grade);	
}

void				Bureaucrat::signForm(Form &arg)
{
	if (!arg.beSigned(*this))
		std::cout << this->_name << " signed " << arg.get_name() << "." << std::endl;
	else
	{
		std::cout << this->_name << " couldn't sign " << arg.get_name() << " because ";
		if (this->_grade > arg.get_sign_grade())
		{
			std::cout << "grade too low."<< std::endl;
		}
		else if (arg.get_sign())
		{
			std::cout << "alredy sign."<< std::endl;
		}
	}
}

void				Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		form.action();
		std::cout << this->_name << " executed " << form.get_name() << std::endl;
	}
	catch (Form::ExecutionNotPossible &e)
	{
		e.print_error();
	}
}

/* static */void	Bureaucrat::GradeTooHighException::print_error(void)
{
	std::cout << "Grade too high exception!" << std::endl;
}

/* static */void	Bureaucrat::GradeTooLowException::print_error(void)
{
	std::cout << "Grade too low exception!" << std::endl;
}


/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
