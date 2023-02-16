/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/16 10:39:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <exception>
# include <iterator>
# include <deque>

template<class T, class Container = deque<T> >
class MutantStack
{
public:

	class MyIterator : public std::iterator<std::bidirectional_iterator_tag, unsigned int>
	{
		public:
		
			MyIterator(unsigned int	*x);
			MyIterator(const MyIterator& mit);
			~MyIterator(void);

			MyIterator		&operator = (const MutantStack::MyIterator &right);
			MyIterator		&operator ++ ();
			MyIterator		operator ++ (int);
			bool			operator == (const MyIterator& rhs) const;
			bool			operator != (const MyIterator& rhs) const;
			unsigned int	&operator * ();
			
		protected:

		private:
		
			unsigned int *p;
	};

	MutantStack(unsigned int	stock_size_max);
	MutantStack(const MutantStack &src);
	~MutantStack(void);

	MutantStack			&operator = (const MutantStack &right);
	void			addNumber(unsigned int nb);
	void			addrangeiterators(MutantStack::MyIterator first, MutantStack::MyIterator last);
	unsigned int	shortestMutantStack(void);
	unsigned int	longestMutantStack(void);
	void			print_stock(void) const;
	unsigned int	*begin(void) const;
	unsigned int	*end(void) const;

	MutantStack			&operator++(void);
	MutantStack			&operator++(int);

protected:

private:

	const unsigned int	_stock_size_max;
	unsigned int		_stock_size;
	unsigned int		*_stock;
};

#endif
