/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/03 15:05:15 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
WrongAnimal::WrongAnimal(void)
{
	std::cout << "\033[00;02;03m" << "WrongAnimal : Default constructor called" << "\033[00m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "\033[00;02;03m" << "WrongAnimal : String constructor called" << "\033[00m" << std::endl;
	this->_type = type;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "\033[32;02;03m" << "WrongAnimal : Copy constructor called" << "\033[00m" << std::endl;
	this->_type = src.getType();
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "\033[31;01m" << "WrongAnimal : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

WrongAnimal		&WrongAnimal::operator=(const WrongAnimal &right)
{
	std::cout << "\033[33;02;03m" << "WrongAnimal : Copy assignment operator called" << "\033[00m" << std::endl;
	this->_type = right.getType();
	return (*this);
}

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

void		WrongAnimal::makeSound(void) const
{
	if (this->_type.empty())
		std::cout << "WrongAnimal" << " : \"Bruit de WrongAnimal.\"" << std::endl;
	else
		std::cout << this->_type << " : \"Bruit de WrongAnimal.\"" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
