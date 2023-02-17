/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/17 09:33:29 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define __MutantStack MutantStack<T, Container>
# define __MS_template template<class T, class Container>

# include <iostream>
# include <string>
# include <exception>
# include <iterator>
# include <deque>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
	
		class iterator : public std::iterator<std::random_access_iterator_tag, T>
		{
			public:
			
				iterator(T *x);
				iterator(const iterator &src);
				~iterator(void);
	
				iterator		&operator = (const iterator &right);
				iterator		&operator ++ (void);
				iterator		operator ++ (int);
				iterator		&operator -- (void);
				iterator		operator -- (int);
				bool			operator == (const iterator &right) const;
				bool			operator != (const iterator &right) const;
				T				&operator * (void);
				int				operator > (const iterator &right);
				int				operator < (const iterator &right);
				int				operator >= (const iterator &right);
				int				operator <= (const iterator &right);
				int				operator == (const iterator &right);
				
			protected:
	
			private:
			
				T *_p;
		};
	
		MutantStack(void);
		MutantStack(const Container &ctnr);
		MutantStack(const MutantStack &src);
		~MutantStack(void);
	
		bool		empty(void) const;
		size_t		size(void) const;
		T			&top(void);
		void		push(const T &val);
		void		emplace(T &val);
		void		pop(void);
		T		*begin(void) const;
		T		*end(void) const;
	
	protected:
	
	private:
	
		Container	_stock;
};

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
__MS_template
__MutantStack::MutantStack(void)
{
	std::cout << "\033[00;02;03m" << "MutantStack : Void constructor called" << "\033[00m" << std::endl;
}

__MS_template
__MutantStack::MutantStack(const Container &ctnr)
{
	std::cout << "\033[00;02;03m" << "MutantStack : Container constructor called" << "\033[00m" << std::endl;
	_stock = ctnr;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

__MS_template
__MutantStack::MutantStack(const MutantStack &src) : _stock(src._stock)
{
	std::cout << "\033[32;02;03m" << "MutantStack : Copy constructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
__MS_template
__MutantStack::~MutantStack(void)
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

__MS_template
bool	__MutantStack::empty(void) const
{
	return (_stock.empty());
}

__MS_template
size_t	__MutantStack::size(void) const
{
	return (_stock.size());
}

__MS_template
T	&__MutantStack::top(void)
{
	if (_stock.empty())
		throw (std::exception());
	return (_stock.back());
}

__MS_template
void	__MutantStack::push(const T &val)
{
	_stock.push_back(val);
}

__MS_template
void	__MutantStack::emplace(T &val)
{
	_stock.emplace_back(val);
}

__MS_template
void	__MutantStack::pop(void)
{
	_stock.pop_back();
}

__MS_template
T		*__MutantStack::begin(void) const
{
	return (const_cast<T *>(&_stock.front()));
}

__MS_template	
T		*__MutantStack::end(void) const
{
	return (const_cast<T *>(&_stock.back()));
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
__MS_template
__MutantStack::iterator::iterator(T *x) : _p(x)
{
//	std::cout << "\033[00;02;03m" << "iterator : Default constructor called" << "\033[00m" << std::endl;
}

/*   COPY CONSTRUCTEUR   **************************************************** */
__MS_template
__MutantStack::iterator::iterator(const __MutantStack::iterator &src) :  _p(src._p)
{
//	std::cout << "\033[32;02;03m" << "iterator : Copy constructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
__MS_template
__MutantStack::iterator::~iterator(void)
{
//	std::cout << "\033[31;01m" << "iterator : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */
__MS_template
class __MutantStack::iterator		&__MutantStack::iterator::operator = (const iterator &right)
{
	_p = right._p;
	return (*this);
}

__MS_template
class __MutantStack::iterator		&__MutantStack::iterator::operator ++ (void)
{
	++_p;
	return (*this);
}

__MS_template
class __MutantStack::iterator		__MutantStack::iterator::operator ++ (int)
{
	__MutantStack::iterator	tmp(*this);

	operator++();
	return (tmp);
}

__MS_template
class __MutantStack::iterator		&__MutantStack::iterator::operator -- (void)
{
	--_p;
	return (*this);
}

__MS_template
class __MutantStack::iterator		__MutantStack::iterator::operator -- (int)
{
	__MutantStack::iterator	tmp(*this);

	operator--();
	return (tmp);
}

__MS_template
bool	__MutantStack::iterator::operator == (const iterator &right) const {
	return (_p == right._p); }

__MS_template
bool	__MutantStack::iterator::operator != (const iterator &right) const {
	return (_p != right._p); }

__MS_template
T		&__MutantStack::iterator::operator * (void) {
	return (*_p); }

__MS_template
int		__MutantStack::iterator::operator > (const iterator &right) {
	return (_p > right._p); }

__MS_template
int		__MutantStack::iterator::operator < (const iterator &right) {
	return (_p < right._p); }

__MS_template
int		__MutantStack::iterator::operator >= (const iterator &right) {
	return (_p  >= right._p); }

__MS_template
int		__MutantStack::iterator::operator <= (const iterator &right) {
	return (_p  <= right._p); }

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
