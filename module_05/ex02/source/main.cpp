/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/08 21:55:51 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

//static void	wait_return(void);

int main(void)
{
	try
	{
		{
			Bureaucrat				tom("Tom", 1);
			RobotomyRequestForm		a("target");
	
			std::cout << a << std::endl;
			tom.executeForm(a);
			tom.signForm(a);
			tom.executeForm(a);
		}
		{
			Bureaucrat				tom("Tom", 1);
			ShrubberyCreationForm		a("target");
	
			std::cout << a << std::endl;
			tom.executeForm(a);
			tom.signForm(a);
			tom.executeForm(a);
		}
		{
			Bureaucrat				tom("Tom", 1);
			PresidentialPardonForm	a("target");
	
			std::cout << a << std::endl;
			tom.executeForm(a);
			tom.signForm(a);
			tom.executeForm(a);
		}
		{
			Bureaucrat				tom("Tom", 1);
			Form					*a = new PresidentialPardonForm("target");
	
			std::cout << *a << std::endl;
			tom.executeForm(*a);
			tom.signForm(*a);
			tom.executeForm(*a);
			delete a;
		}
		{
			Bureaucrat				tom("Tom", 25);
			PresidentialPardonForm	a("target");
	
			std::cout << a << std::endl;
			tom.executeForm(a);
			tom.signForm(a);
			tom.executeForm(a);
		}
		{
			Bureaucrat				tom("Tom", 150);
			PresidentialPardonForm	a("target");
	
			std::cout << a << std::endl;
			tom.executeForm(a);
			tom.signForm(a);		// <--- throw exception
			tom.executeForm(a);		// x
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
