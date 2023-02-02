/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/02 20:52:29 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Cat::Cat(void) : Animal("Cat")
{
	std::cout << "\033[00;02;03m" << "Cat : Default constructor called" << "\033[00m" << std::endl;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

Cat::Cat(const Cat &src) : Animal("Cat")
{
	std::cout << "\033[32;02;03m" << "Cat : Copy constructor called" << "\033[00m" << std::endl;
	(void) src;
//	this->_type = src.getType();
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Cat::~Cat(void)
{
	std::cout << "\033[31;01m" << "Cat : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

Cat	&Cat::operator=(const Cat &right)
{
	std::cout << "\033[33;02;03m" << "Cat : Copy assignment operator called" << "\033[00m" << std::endl;
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

void	Cat::makeSound(void) const
{
	std::cout << this->_type << " : \"Miaou.\"" << std::endl;
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
