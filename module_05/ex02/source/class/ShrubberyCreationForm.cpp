/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:49:33 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/08 17:53:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 25, 5), _target(target)
{
	std::cout << "\033[00;02;03m" << "ShrubberyCreationForm : Default constructor called" << "\033[00m" << std::endl;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form(src.get_name(), src.get_sign_grade(), src.get_exec_grade()), _target(src.get_target())
{
	std::cout << "\033[32;02;03m" << "ShrubberyCreationForm : Copy constructor called" << "\033[00m" << std::endl;
	(void) src;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "\033[31;01m" << "ShrubberyCreationForm : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

ShrubberyCreationForm		&ShrubberyCreationForm::operator = (const ShrubberyCreationForm &right)
{
	std::cout << "\033[33;02;03m" << "ShrubberyCreationForm : Copy assignment operator called" << "\033[00m" << std::endl;
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

std::string	ShrubberyCreationForm::get_target() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::action(void)
{
	std::ofstream	ofs((this->_target + "_shrubbery").c_str());

	if (!ofs.is_open())
		throw (FileNotOpen());
	ofs << "* * * *\n"
		<< "| | | |\n";
	ofs.close();
}

/* static */void	ShrubberyCreationForm::FileNotOpen::print_error(void)
{
	std::cout << "File not open." << std::endl;
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
