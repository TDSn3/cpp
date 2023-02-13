/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:49:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/13 15:59:13 by tda-silv         ###   ########.fr       */
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
		Array(T n);
		Array(const Array &src);
		~Array(void);
	
		Array	&operator = (const Array &right);
		T		&operator [] (const T &x);

	protected:

	private:
		T	*tab;
		T	tab_size;
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
Array<T>::Array(T n)
{
	std::cout << "\033[00;02;03m" << "Array : Number constructor called" << "\033[00m" << std::endl;
	tab = new T[n];
	tab_size = n;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

template<typename T>
Array<T>::Array(const Array &src)
{
	std::cout << "\033[32;02;03m" << "Array : Copy constructor called" << "\033[00m" << std::endl;
	
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
	std::cout << "\033[33;02;03m" << "Array : Copy assignment operator called" << "\033[00m" << std::endl;
	(void) right;
	
	return (*this);
}

template<typename T>
T		&Array<T>::operator [] (const T &x)
{
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

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */


#endif