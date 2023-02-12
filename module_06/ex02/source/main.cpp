/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/12 16:07:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

//static void	wait_return(void);
Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int main(void)
{
	Base	*x = generate();

	identify(x);
	identify(*x);
	delete x;
	return (0);
}

Base	*generate(void)
{
	Base	*new_Base;
	int		i_random;

	srand(static_cast<unsigned int>(time(NULL)));
	i_random = rand() % 3 + 1;
	switch (i_random)
	{
		case 1:
			new_Base = new A;
			std::cout << "Class A created" << std::endl;
			break;
		case 2:
			new_Base = new B;
			std::cout << "Class B created" << std::endl;
			break;
		case 3:
			new_Base = new C;
			std::cout << "Class C created" << std::endl;
			break;
	}
	return (new_Base);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Ptr : Class A detected" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "Ptr : Class B detected" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "Ptr : Class C detected" << std::endl;
}

void	identify(Base &p)
{	
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "Ref : Class A detected" << std::endl;
	}
	catch (const std::bad_cast &e) {}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "Ref : Class B detected" << std::endl;
	}
	catch (const std::bad_cast &e) {}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "Ref : Class C detected" << std::endl;
	}
	catch (const std::bad_cast &e) {}
}

//static void	wait_return(void)
//{
//	std::cout << "\033[00;02;03m"
//	<< "Press any key to continue"
//	<< "\033[00m" << std::endl;
//	std::cin.get();
//}
