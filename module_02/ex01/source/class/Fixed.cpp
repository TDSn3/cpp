/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/20 19:26:30 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>
# include <iostream>
# include <string>

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

typedef int32_t	t_fixed;

t_fixed	float_to_fixed(float nb)
{
	return (t_fixed)(nb * 65536.0f / 16.0f);
}

Fixed::Fixed(const float nb) : _size_fract(8)
{
	std::cout << "\033[32;02;03m" << "Constructor 3 called" << "\033[00m" << std::endl;
	std::cout << nb << std::endl;
	std::cout << (float_to_fixed(nb)>>4) << std::endl;
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

/*   PUBLIC   **************************************************************** */

int	Fixed::getRawBits(void) const
{
	std::cout << "\033[36;02;03m" << "getRawBits member function called" << "\033[00m" << std::endl;
	return (this->_nb);
}

void	Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
}

/*   PRIVATE   *************************************************************** */

