/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:00:45 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/16 22:20:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Span::Span(unsigned int	stock_size_max) : _stock_size_max(stock_size_max)
{
	std::cout << "\033[00;02;03m" << "Span : Default constructor called" << "\033[00m" << std::endl;
	if (stock_size_max == 0)
		throw (std::exception());
	_stock = new unsigned int [_stock_size_max];
	_stock_size = 0;
}

/*   COPY CONSTRUCTEUR   **************************************************** */
 
Span::Span(const Span &src) : _stock_size_max(src._stock_size_max)
{
	std::cout << "\033[32;02;03m" << "Span : Copy constructor called" << "\033[00m" << std::endl;
	_stock = new unsigned int [src._stock_size_max];
	for (unsigned int i = 0; i < src._stock_size_max; i++)
		_stock[i] = src._stock[i];
	_stock_size = src._stock_size;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Span::~Span(void)
{
	std::cout << "\033[31;01m" << "Span : Destructor called" << "\033[00m" << std::endl;
	delete [] _stock;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

Span	&Span::operator = (const Span &right)
{
	std::cout << "\033[33;02;03m" << "Span : Copy assignment operator called" << "\033[00m" << std::endl;
	delete [] _stock;
	_stock = new unsigned int [right._stock_size_max];
	for (unsigned int i = 0; i < right._stock_size_max; i++)
		_stock[i] = right._stock[i];
	_stock_size = right._stock_size;
	return (*this);
}

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

void	Span::addNumber(unsigned int nb)
{
	if (_stock_size == _stock_size_max)
		throw (std::exception());
	_stock[_stock_size] = nb;
	_stock_size++;
}

void	Span::addrangeiterators(Span::MyIterator first, Span::MyIterator last)
{
	if (first > last)
		throw (std::exception());
	while (first != last)
	{
		addNumber(*first);
		first++;
	}
	addNumber(*first);
}

unsigned int	Span::shortestSpan(void)
{
	if (_stock_size < 2)
		throw (std::exception());

	std::vector<unsigned int>	stock_stock(_stock, _stock + _stock_size);
	unsigned int				min = *(stock_stock.end() - 1);

	std::sort(stock_stock.begin(), stock_stock.end());
	for (std::vector<unsigned int>::iterator it = stock_stock.begin(); it != stock_stock.end(); it++)
	{
		if (it + 1 != stock_stock.end())
			if (*(it + 1) - *it < min)
				min = *(it + 1) - *it;
	}
	return (min);
}

unsigned int	Span::longestSpan(void)
{
	if (_stock_size < 2)
		throw (std::exception());

	unsigned int	stock_min;
	unsigned int	stock_max;

	stock_min = *std::min_element(_stock, _stock + _stock_size);
	stock_max = *std::max_element(_stock, _stock + _stock_size);

	return (stock_max - stock_min);
}

void	Span::print_stock(void) const
{
	for (unsigned int i = 0; i < _stock_size; i++)
		std::cout << _stock[i] << std::endl;
}

unsigned int	*Span::begin(void) const
{
	if (_stock_size < 1)
		return (NULL);
	return (&_stock[0]);
}
	
unsigned int	*Span::end(void) const
{
	if (_stock_size < 1)
		return (NULL);
	return (&_stock[_stock_size - 1]);
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
