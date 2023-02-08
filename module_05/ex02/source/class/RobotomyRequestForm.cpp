/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:40:24 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/08 21:52:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 25, 5), _target(target)
{
	std::cout << "\033[00;02;03m" << "RobotomyRequestForm : Default constructor called" << "\033[00m" << std::endl;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form(src.get_name(), src.get_sign_grade(), src.get_exec_grade()), _target(src.get_target())
{
	std::cout << "\033[32;02;03m" << "RobotomyRequestForm : Copy constructor called" << "\033[00m" << std::endl;
	(void) src;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "\033[31;01m" << "RobotomyRequestForm : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

RobotomyRequestForm		&RobotomyRequestForm::operator = (const RobotomyRequestForm &right)
{
	std::cout << "\033[33;02;03m" << "RobotomyRequestForm : Copy assignment operator called" << "\033[00m" << std::endl;
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

std::string	RobotomyRequestForm::get_target() const
{
	return (this->_target);
}

void	RobotomyRequestForm::action(void) const
{
	int	i_random;
	
	srand((unsigned int) time(NULL));
	i_random = rand() % 100;
	std::cout << "Bruits de perceuse." << std::endl;
	if (i_random % 2)
		std::cout << this->get_name() << "a été robotomisée avec succès!" << std::endl;
	else
		std::cout << this->get_name() << "n'a pas été robotomisée..." << std::endl;
}

/* static */void	RobotomyRequestForm::FileNotOpen::print_error(void)
{
	std::cout << "File not open." << std::endl;
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
