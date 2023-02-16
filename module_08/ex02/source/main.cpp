/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/16 23:57:09 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

int main(void)
{
	std::vector<int>	vect_a;
	
	vect_a.push_back(10);
	vect_a.push_back(9);
	vect_a.push_back(8);




	MutantStack<int, std::vector<int> >	a(vect_a);
	std::stack<int, std::vector<int> >	b(vect_a);




	b.push(55);
	std::cout << b.top() << std::endl;
	b.pop();
	std::cout << b.top() << std::endl;
	b.pop();
	std::cout << b.top() << std::endl;
	b.pop();
	std::cout << b.top() << std::endl;

	std::cout << "----------" << std::endl;

	a.push(55);
	std::cout << a.top() << std::endl;
	a.pop();
	std::cout << a.top() << std::endl;
	a.pop();
	std::cout << a.top() << std::endl;
	a.pop();
	std::cout << a.top() << std::endl;




	return (0);
}

/*
int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
	    std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}
*/