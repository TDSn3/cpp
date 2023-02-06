/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/06 13:42:18 by tda-silv         ###   ########.fr       */
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
{	this->_nb = 0; }

Fixed::Fixed(const int nb) : _size_fract(8)
{	_nb = nb << this->_size_fract; }

Fixed::Fixed(const float nb) : _size_fract(8)
{	_nb = roundf(nb * 256.0f); }

/*   COPY   ***************************************************************** */

Fixed::Fixed(const Fixed &fixed_b) : _size_fract(8)
{	_nb = fixed_b.getRawBits(); }

/* ************************************************************************** */
/*                                                                            */
/*   Destructeur															  */
/*                                                                            */
/* ************************************************************************** */
Fixed::~Fixed(void)
{
//	std::cout << "\033[31;01m" << "Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   Opérateur d'affectation												  */
/*                                                                            */
/* ************************************************************************** */

/*   INTERNE   *************************************************************** */

Fixed	&Fixed::operator = (const Fixed &right)
{
	this->_nb = right.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator + (const Fixed &right)
{
	this->_nb = roundf((this->toFloat() + right.toFloat()) * 256.0f);
	return (*this);
}

Fixed	&Fixed::operator - (const Fixed &right)
{
	this->_nb = roundf((this->toFloat() - right.toFloat()) * 256.0f);
	return (*this);
}

Fixed	&Fixed::operator * (const Fixed &right)
{
	this->_nb = roundf((this->toFloat() * right.toFloat()) * 256.0f);
	return (*this);
}
Fixed	&Fixed::operator / (const Fixed &right)
{
	this->_nb = roundf((this->toFloat() / right.toFloat()) * 256.0f);
	return (*this);
}

Fixed	&Fixed::operator ++ (void)
{
	++(this->_nb);
	return (*this);
}

Fixed	Fixed::operator ++ (int useless)
{
	Fixed	return_fixed;

	return_fixed = *this;
	(void) useless;
	(this->_nb)++;
	return (return_fixed);
}

Fixed	&Fixed::operator -- (void)
{
	--(this->_nb);
	return (*this);
}

Fixed	Fixed::operator -- (int useless)
{
	Fixed	return_fixed;

	(void) useless;
	return_fixed = *this;
	(this->_nb)--;
	return (return_fixed);
}

/*   EXTERNE   *************************************************************** */

std::ostream	&operator << (std::ostream &left, const Fixed &right)
{
	left << right.toFloat();
	return (left);
}

int	operator > (const Fixed &left, const Fixed &right)
{	return (left.toFloat() > right.toFloat()); }

int	operator < (const Fixed &left, const Fixed &right)
{	return (left.toFloat() < right.toFloat()); }

int	operator >= (const Fixed &left, const Fixed &right)
{	return (left.toFloat() >= right.toFloat()); }

int	operator <= (const Fixed &left, const Fixed &right)
{	return (left.toFloat() <= right.toFloat()); }

int	operator == (const Fixed &left, const Fixed &right)
{	return (left.toFloat() == right.toFloat()); }

int	operator != (const Fixed &left, const Fixed &right)
{	return (left.toFloat() != right.toFloat()); }

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   PUBLIC   *************************************************************** */

int		Fixed::getRawBits(void) const
{	return (this->_nb); }

void	Fixed::setRawBits(int const raw)
{	this->_nb = raw; }

int		Fixed::toInt(void) const
{	return (this->_nb >> this->_size_fract); }

float	Fixed::toFloat(void) const
{	return (this->_nb / 256.0f); }

/* static */ Fixed	&Fixed::min(Fixed &x, Fixed &y)
{	
	if (x.toFloat() < y.toFloat())
		return (x);
	else
		return (y);
}

/* static */ const Fixed	&Fixed::min(const Fixed &x, const Fixed &y)
{
	if (x.toFloat() < y.toFloat())
		return (x);
	else
		return (y);
}

/* static */ Fixed	&Fixed::max(Fixed &x, Fixed &y)
{
	if (x.toFloat() > y.toFloat())
		return (x);
	else
		return (y);
}

/* static */ const Fixed	&Fixed::max(const Fixed &x, const Fixed &y)
{
	if (x.toFloat() > y.toFloat())
		return (x);
	else
		return (y);
}

/*   PRIVATE   ************************************************************** */

/* ************************************************************************** */
