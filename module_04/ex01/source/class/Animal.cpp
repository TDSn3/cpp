/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/03 19:31:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Animal::Animal(void)
{
	std::cout << "\033[00;02;03m" << "Animal : Default constructor called" << "\033[00m" << std::endl;
}

Animal::Animal(std::string type)
{
	std::cout << "\033[00;02;03m" << "Animal : String constructor called" << "\033[00m" << std::endl;
	this->_type = type;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

Animal::Animal(const Animal &src)
{
	std::cout << "\033[32;02;03m" << "Animal : Copy constructor called" << "\033[00m" << std::endl;
	this->_type = src.getType();
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Animal::~Animal(void)
{
	std::cout << "\033[31;01m" << "Animal : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

Animal		&Animal::operator=(const Animal &right)
{
	std::cout << "\033[33;02;03m" << "Animal : Copy assignment operator called" << "\033[00m" << std::endl;
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

void		Animal::makeSound(void) const
{
	if (this->_type.empty())
		std::cout << "Animal" << " : \"Bruit d'animal.\"" << std::endl;
	else
		std::cout << this->_type << " : \"Bruit d'animal.\"" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
