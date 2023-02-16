/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/16 16:29:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <iterator>

class Span
{
public:

	class MyIterator : public std::iterator<std::bidirectional_iterator_tag, unsigned int>
	{
		public:
		
			MyIterator(unsigned int	*x);
			MyIterator(const MyIterator& mit);
			~MyIterator(void);

			MyIterator		&operator = (const Span::MyIterator &right);
			MyIterator		&operator ++ ();
			MyIterator		operator ++ (int);
			bool			operator == (const MyIterator& rhs) const;
			bool			operator != (const MyIterator& rhs) const;
			unsigned int	&operator * ();
			
		protected:

		private:
		
			unsigned int *p;
	};

	Span(unsigned int	stock_size_max);
	Span(const Span &src);
	~Span(void);

	Span			&operator = (const Span &right);
	void			addNumber(unsigned int nb);
	template <class T<unsigned int> >
	void			addrangeiterators(T first, T last);
	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void);
	void			print_stock(void) const;
	unsigned int	*begin(void) const;
	unsigned int	*end(void) const;

	Span			&operator++(void);
	Span			&operator++(int);

protected:

private:

	const unsigned int	_stock_size_max;
	unsigned int		_stock_size;
	unsigned int		*_stock;
};

template <class T<unsigned int> >
void	Span::addrangeiterators(T first,  T last)
{
	while (first != last)
	{
		addNumber(*first);
		first++;
	}
	//addNumber(*first);
}
#endif
