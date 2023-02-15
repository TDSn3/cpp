/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/15 21:44:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

int main(void)
{
	Span			a(1e4);	// 1 * 10^4 = 10 000
	unsigned int	tab[1000];

	for (int i = 0; i < 1000; i++)
		tab[i] = static_cast<unsigned int>(i);
	try
	{
		a.addNumber(7);
		a.addNumber(1);
		a.addNumber(5);
		a.addNumber(9);
		a.addNumber(3);
		a.addNumber(3);

		a.print_stock();

		std::cout << "-----------" << std::endl;
		std::cout << a.longestSpan() << std::endl;
		std::cout << "-----------" << std::endl;
		std::cout << a.shortestSpan() << std::endl;
		std::cout << "-----------" << std::endl;

		Span::MyIterator	it_1 = &tab[0];
		Span::MyIterator	it_2 = &tab[10];
	
		a.addrangeiterators(it_1, it_2);
		std::cout << "-----------" << std::endl;

		a.print_stock();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
