/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastScalaire.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:00:45 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/10 18:36:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
CastScalaire::CastScalaire(int arg)
{
	std::cout << "\033[00;02;03m" << "CastScalaire : Int constructor called" << "\033[00m" << std::endl;
	_stock_data = reinterpret_cast < __int64_t &> (arg);
	_index[0] = 1;
	_index[1] = 0;
	_index[2] = 0;
	_index[3] = 0;
}

CastScalaire::CastScalaire(float arg)
{
	std::cout << "\033[00;02;03m" << "CastScalaire : Float constructor called" << "\033[00m" << std::endl;
	_stock_data = reinterpret_cast < __int64_t &> (arg);
	_index[0] = 0;
	_index[1] = 1;
	_index[2] = 0;
	_index[3] = 0;
}

CastScalaire::CastScalaire(double arg)
{
	std::cout << "\033[00;02;03m" << "CastScalaire : Double constructor called" << "\033[00m" << std::endl;
	_stock_data = reinterpret_cast < __int64_t &> (arg);
	_index[0] = 0;
	_index[1] = 0;
	_index[2] = 1;
	_index[3] = 0;
}

CastScalaire::CastScalaire(char arg)
{
	std::cout << "\033[00;02;03m" << "CastScalaire : Char constructor called" << "\033[00m" << std::endl;
	_stock_data = reinterpret_cast < __int64_t &> (arg);
	_index[0] = 0;
	_index[1] = 0;
	_index[2] = 0;
	_index[3] = 1;
}

CastScalaire::CastScalaire(std::string arg)
{
	std::cout << "\033[00;02;03m" << "CastScalaire : String constructor called" << "\033[00m" << std::endl;
	if (   arg == "-inff"
		|| arg == "+inff"
		|| arg == "nanf"
		|| arg == "-inf"
		|| arg == "+inf"
		|| arg == "nan")
	{
		_stock_arg = arg;
		_stock_data = 0;
	}
	else
		throw (InvalidString());
}

/*   COPY CONSTRUCTEUR   **************************************************** */
 
CastScalaire::CastScalaire(const CastScalaire &src)
{
	std::cout << "\033[32;02;03m" << "CastScalaire : Copy constructor called" << "\033[00m" << std::endl;
	_stock_data = src._stock_data;
	_index[0] = src._index[0];
	_index[1] = src._index[1];
	_index[2] = src._index[2];
	_index[3] = src._index[3];
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
CastScalaire::~CastScalaire(void)
{
	std::cout << "\033[31;01m" << "CastScalaire : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

CastScalaire	&CastScalaire::operator = (const CastScalaire &right)
{
	std::cout << "\033[33;02;03m" << "CastScalaire : Copy assignment operator called" << "\033[00m" << std::endl;
	_stock_data = right._stock_data;
	_index[0] = right._index[0];
	_index[1] = right._index[1];
	_index[2] = right._index[2];
	_index[3] = right._index[3];
	return (*this);
}

CastScalaire::operator int(void)
{
	if (_index[0] == 1)
		return (static_cast<int>(reinterpret_cast<int&>(_stock_data)));
	else if (_index[1] == 1)
		return (static_cast<int>(reinterpret_cast<float&>(_stock_data)));
	else if (_index[2] == 1)
		return (static_cast<int>(reinterpret_cast<double&>(_stock_data)));
	else if (_index[3] == 1)
		return (static_cast<int>(reinterpret_cast<char&>(_stock_data)));
	return (0);
}

CastScalaire::operator float(void)
{
	if (_index[0] == 1)
		return (static_cast<float>(reinterpret_cast<int&>(_stock_data)));
	else if (_index[1] == 1)
		return (static_cast<float>(reinterpret_cast<float&>(_stock_data)));
	else if (_index[2] == 1)
		return (static_cast<float>(reinterpret_cast<double&>(_stock_data)));
	else if (_index[3] == 1)
		return (static_cast<float>(reinterpret_cast<char&>(_stock_data)));
	return (0);
}

CastScalaire::operator double(void)
{
	if (_index[0] == 1)
		return (static_cast<double>(reinterpret_cast<int&>(_stock_data)));
	else if (_index[1] == 1)
		return (static_cast<double>(reinterpret_cast<float&>(_stock_data)));
	else if (_index[2] == 1)
		return (static_cast<double>(reinterpret_cast<double&>(_stock_data)));
	else if (_index[3] == 1)
		return (static_cast<double>(reinterpret_cast<char&>(_stock_data)));
	return (0);
}

CastScalaire::operator char(void)
{
	if (_index[0] == 1)
		return (static_cast<char>(reinterpret_cast<int&>(_stock_data)));
	else if (_index[1] == 1)
		return (static_cast<char>(reinterpret_cast<float&>(_stock_data)));
	else if (_index[2] == 1)
		return (static_cast<char>(reinterpret_cast<double&>(_stock_data)));
	else if (_index[3] == 1)
		return (static_cast<char>(reinterpret_cast<char&>(_stock_data)));
	return (0);
}

CastScalaire::operator std::string(void)
{
	return (_stock_arg);
}

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

void	CastScalaire::InvalidString::print_error(void) const
{
	std::cout << "CastScalaire : Invalid string in constructor string" << std::endl;
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
