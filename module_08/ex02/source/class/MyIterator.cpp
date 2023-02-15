/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyIterator.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:52:16 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/15 21:58:31 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>
typedef Span::MyIterator MyIterator;

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
MyIterator::MyIterator(unsigned int	*x) : p(x)
{
	std::cout << "\033[00;02;03m" << "MyIterator : Default constructor called" << "\033[00m" << std::endl;
}

/*   COPY CONSTRUCTEUR   **************************************************** */
 
MyIterator::MyIterator(const MyIterator &src) :  p(src.p)
{
	std::cout << "\033[32;02;03m" << "MyIterator : Copy constructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
MyIterator::~MyIterator(void)
{
	std::cout << "\033[31;01m" << "MyIterator : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

MyIterator	&MyIterator::operator = (const MyIterator &right)
{
	p = right.p;
	return (*this);
}

MyIterator	&MyIterator::operator ++ ()
{
	++p;
	return (*this);
}

MyIterator	MyIterator::operator++(int)
{
	MyIterator	tmp(*this);

	operator++();
	return (tmp);
}

bool	MyIterator::operator==(const MyIterator& rhs) const
{
	return (p==rhs.p);
}

bool	MyIterator::operator!=(const MyIterator& rhs) const
{
	return (p!=rhs.p);
}

unsigned int	&MyIterator::operator*()
{
	return (*p);
}


/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
