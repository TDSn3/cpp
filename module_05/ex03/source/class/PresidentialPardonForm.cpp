/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:50:19 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/08 22:41:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("presidential pardon", 25, 5),  _target(target)
{
	std::cout << "\033[00;02;03m" << "PresidentialPardonForm : Default constructor called" << "\033[00m" << std::endl;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : Form(src.get_name(), src.get_sign_grade(), src.get_exec_grade()), _target(src.get_target())
{
	std::cout << "\033[32;02;03m" << "PresidentialPardonForm : Copy constructor called" << "\033[00m" << std::endl;
	(void) src;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "\033[31;01m" << "PresidentialPardonForm : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

PresidentialPardonForm		&PresidentialPardonForm::operator = (const PresidentialPardonForm &right)
{
	std::cout << "\033[33;02;03m" << "PresidentialPardonForm : Copy assignment operator called" << "\033[00m" << std::endl;
	(void) right;
	return (*this);
}

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

std::string	PresidentialPardonForm::get_target() const
{
	return (this->_target);
}

void	PresidentialPardonForm::action(void)
{
	std::cout << this->_target << " a été pardonnée par Zaphod Beeblebrox." << std::endl;
}


/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
