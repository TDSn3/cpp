/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/08 11:42:19 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

//static void	wait_return(void);

int main(void)
{
	try
	{
		{
			Bureaucrat	a("Alfred", 1);
			Form		doc("Number_1", 50, 10);

			std::cout << a << std::endl;
			std::cout << doc << std::endl;
			a.signForm(doc);
			a.signForm(doc);
		}
		{
			Bureaucrat	a("Gontrand", 150);
			Form		doc("Number_2", 50, 10);

			std::cout << a << std::endl;
			std::cout << doc << std::endl;
			a.signForm(doc);
		}
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
