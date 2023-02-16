/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/16 12:46:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <exception>
# include <iterator>
# include <deque>

template<class T, class Container = std::deque<T> >
class MutantStack
{
public:

	class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		public:
		
			iterator(T	*x);
			iterator(const iterator& mit);
			~iterator(void);

			iterator		&operator = (const iterator &right);
			iterator		&operator ++ ();
			iterator		operator ++ (int);
			bool			operator == (const iterator& rhs) const;
			bool			operator != (const iterator& rhs) const;
			T	&operator * ();
			
		protected:

		private:
		
			T *p;
	};

	MutantStack(T const &nb);
	MutantStack(const MutantStack &src);
	~MutantStack(void);

	T	&top(void);

protected:

private:

	Container	_stock;
};

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
template<class T, class Container>
MutantStack<T, Container>::MutantStack(T nb)
{
	std::cout << "\033[00;02;03m" << "MutantStack : Default constructor called" << "\033[00m" << std::endl;
	_stock.push_back(nb);
	(void) nb;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

template<class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &src)
{
	std::cout << "\033[32;02;03m" << "MutantStack : Copy constructor called" << "\033[00m" << std::endl;
	(void) src;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
template<class T, class Container>
MutantStack<T, Container>::~MutantStack(void)
{
	std::cout << "\033[31;01m" << "MutantStack : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

template<class T, class Container>
T	&MutantStack<T, Container>::top(void)
{
	return (_stock.back());
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */



#endif
