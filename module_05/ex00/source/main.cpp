/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/10 10:13:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

//static void	wait_return(void);

int main(void)
{
	try
	{
		Bureaucrat	a("Alfred", 150);

		std::cout << a << std::endl;
		++a;
		std::cout << a << std::endl;
		a--;
		std::cout << a << std::endl;
		a--;
		std::cout << a << std::endl;
		a--;
		std::cout << a << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		e.print_error();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		e.print_error();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception!" <<std::endl;
	}
	return (0);
}

//static void	wait_return(void)
//{
//	std::cout << "\033[00;02;03m"
//	<< "Press any key to continue"
//	<< "\033[00m" << std::endl;
//	std::cin.get();
//}
