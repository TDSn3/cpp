/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:32:39 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/10 11:45:00 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Intern::Intern(void)
{
	std::cout << "\033[00;02;03m" << "Intern : Default constructor called" << "\033[00m" << std::endl;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

Intern::Intern(const Intern &src)
{
	std::cout << "\033[32;02;03m" << "Intern : Copy constructor called" << "\033[00m" << std::endl;
	(void) src;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Intern::~Intern(void)
{
	std::cout << "\033[31;01m" << "Intern : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

Intern		&Intern::operator = (const Intern &right)
{
	std::cout << "\033[33;02;03m" << "Intern : Copy assignment operator called" << "\033[00m" << std::endl;
	(void) right;
	return (*this);
}

Form	*Intern::makeForm(std::string form_name, std::string form_target)
{
	int	i;
	int	stock;

	i = 0;
	stock = -1;

	this->_tab[0] = new PresidentialPardonForm(form_target);
	this->_tab[1] = new RobotomyRequestForm(form_target);
	this->_tab[2] = new ShrubberyCreationForm(form_target);

	while (i < 3)
	{
		if (this->_tab[i]->get_name() == form_name)
		{
			stock = i;
			i++;
			continue ;
		}
		delete this->_tab[i];
		i++;
	}

	if (stock != -1)
	{
		std::cout << "Intern creates " << form_name << "." << std::endl;
		return (this->_tab[stock]);
	}
	else
	{
		std::cout << "Form do not exist!" << std::endl;
		return (NULL);
	}
}

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
