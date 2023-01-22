/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/22 16:08:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>
# include <iostream>
# include <string>

typedef int32_t fixed;

fixed	float_to_fixed(float nb);

/* ************************************************************************** */
/*                                                                            */
/*   Constructeur															  */
/*                                                                            */
/* ************************************************************************** */
Fixed::Fixed(void) : _size_fract(8)
{
	std::cout << "\033[00;02;03m" << "Default constructor called" << "\033[00m" << std::endl;
	this->_nb = 0;
}

Fixed::Fixed(const int nb) : _size_fract(8)
{
	std::cout << "\033[32;02;03m" << "Constructor 2 called" << "\033[00m" << std::endl;
	_nb = nb << this->_size_fract;
}

Fixed::Fixed(const float nb) : _size_fract(8)
{
	std::cout << "\033[32;02;03m" << "Constructor 3 called" << "\033[00m" << std::endl;
	std::cout << nb << std::endl;
	std::cout << (float_to_fixed(nb)) << std::endl;
}

/*   COPY   ***************************************************************** */

Fixed::Fixed(const Fixed &fixed_b) : _size_fract(8)
{
	std::cout << "\033[32;02;03m" << "Copy constructor called" << "\033[00m" << std::endl;
	_nb = fixed_b.getRawBits();
}

/* ************************************************************************** */
/*                                                                            */
/*   Destructeur															  */
/*                                                                            */
/* ************************************************************************** */
Fixed::~Fixed(void)
{
	std::cout << "\033[31;01m" << "Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   Opérateur d'affectation												  */
/*                                                                            */
/*   Ce renvois lui même après avoir copié les valeurs de "fixed_b".		  */
/*                                                                            */
/* ************************************************************************** */
Fixed	&Fixed::operator=(const Fixed &fixed_b)
{
	std::cout << "\033[33;02;03m" << "Copy assignment operator called" << "\033[00m" << std::endl;
	(void) fixed_b;
	this->_nb = fixed_b.getRawBits();
	return (*this);
}

/*   PUBLIC   *************************************************************** */

int	Fixed::getRawBits(void) const
{
	std::cout << "\033[36;02;03m" << "getRawBits member function called" << "\033[00m" << std::endl;
	return (this->_nb);
}

void	Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
}

/*   PRIVATE   ************************************************************** */

/* ************************************************************************** */

/* ************************************************************************** */
/*   Nombre de bits 			  : 4294967296.0 = 2^32						  */
/*   Nombre de bits avant virgule : 16777216.0   = 2^24						  */
/*   Nombre de bits avant virgule : 256.0        = 2^8						  */
/*                                                                            */
/*  	 							    8 bits après la virgule				  */
/*											    vvvvvvvv					  */
/*   int (32 bits) : -------- -------- -------- --------					  */
/*												   v                          */
/*                            -     -     -     -     -    -    -    -		  */
/*                           2^-1  2^-2  2^-3  2^-4  2^-5 2^-6 2^-7 2^-8      */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Exemple :																  */
/*                                                                            */
/*   nb = 99.333															  */
/*       			seeeeeee emmmmmmm mmmmmmmm mmmmmmmm						  */
/*                                                                            */
/*              	01000010 11000110 10101010 01111111						  */
/*                                                                            */
/*   99.333 * 256.0 = 25429.2                                       	      */
/*       			seeeeeee emmmmmmm mmmmmmmm mmmmmmmm						  */
/*                                                                            */
/*                  01000110 11000110 10101010 01100110						  */
/*                                                                            */
/*                            01000110 11000110 10101010 01100110             */
/*                                     ││││││││ │││││││                       */
/*   25429 =					   	   │││││││└┐│││││││                       */
/*                  00000000 00000000 01100011 01010101                       */

/*   25429 / 256.0 = 99.333 												  */
/* ************************************************************************** */

fixed	float_to_fixed(float nb)
{
	std::cout << (nb * 256.0f) / 256.0f << std::endl;
	return ((fixed)(roundf(nb * 256.0f)));
}

