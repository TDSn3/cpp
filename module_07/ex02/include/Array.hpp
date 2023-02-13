/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:49:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/13 20:58:31 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cctype>

template<typename T>
class Array
{
	public:

		Array(void);
		Array(size_t n);
		Array(const Array &src);
		~Array(void);
	
		Array	&operator = (const Array &right);
		T		&operator [] (const size_t &x);
		size_t	size(void) const;

	protected:

	private:
		T		*tab;
		size_t	tab_size;
};

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
template<typename T>
Array<T>::Array(void)
{
	std::cout << "\033[00;02;03m" << "Array : Void constructor called" << "\033[00m" << std::endl;
	tab = new T[0];
	tab_size = 0;
}

template<typename T>
Array<T>::Array(size_t n)
{
	std::cout << "\033[00;02;03m" << "Array : Number constructor called" << "\033[00m" << std::endl;
	if (n < 0)
		throw (std::exception());
	tab = new T[n];
	tab_size = n;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

template<typename T>
Array<T>::Array(const Array &src)
{
	std::cout << "\033[32;02;03m" << "Array : Copy constructor called" << "\033[00m" << std::endl;
	tab = new T[src.tab_size];
	for (size_t i = 0; i < src.tab_size; i++)
		tab[i] = src.tab[i];
	tab_size = src.tab_size;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
template<typename T>
Array<T>::~Array(void)
{
	std::cout << "\033[31;01m" << "Array : Destructor called" << "\033[00m" << std::endl;
	delete [] tab;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

template<typename T>
Array<T>	&Array<T>::operator = (const Array &right)
{
	std::cout << "\033[33;02;03m" << "Array : Operator = called" << "\033[00m" << std::endl;
	delete	[] tab;
	tab = new T[right.tab_size];
	for (int i = 0; i < right.tab_size; i++)
		tab[i] = right.tab[i];
	tab_size = right.tab_size;
	return (*this);
}

template<typename T>
T		&Array<T>::operator [] (const size_t &x)
{
//	std::cout << "\033[33;02;03m" << "Array : Operator [] called" << "\033[00m" << std::endl;
	if (x >= 0 && x <= tab_size - 1)
		return (tab[x]);
	else
		throw (std::exception());
}

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

template<typename T>
size_t	Array<T>::size(void) const
{
	return (tab_size);
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */


#endif