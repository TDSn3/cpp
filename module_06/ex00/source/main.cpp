/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/12 11:38:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

/* ************************************************************************** */
/*                    │         │        │          │          │              */
/*         CAST       │  CONV.  │ REINT. │  UPCAST  │ DOWNCAST │ TYPE QUAL.   */
/* ───────────────────┼─────────┼────────┼──────────┼──────────┼───────────── */
/*   implicit         │   Yes   │        │   Yes    │          │              */
/*   static_cast      │   Yes   │        │   Yes    │   Yes    │              */
/*   dynamic_cast     │         │        │   Yes    │   Yes    │              */
/*   reinterpret_cast │         │  Yes   │   Yes    │   Yes    │              */
/*   const_cast       │         │        │          │          │     Yes      */
/* ───────────────────┼─────────┼────────┼──────────┼──────────┼───────────── */
/*   legacy "c" cast  │   Yes   │  Yes   │   Yes    |   Yes    │     Yes      */
/*                    │         │        │          │          │              */
/* ************************************************************************** */

//static void	wait_return(void);
static int	check_error(int argc, char **argv);

int main(int argc, char **argv)
{
	if (check_error(argc, argv))
		return (1);
	try
	{
		CastScalaire	x(argv[1]);
		int				a = x;
		float			b = x;
		double			c = x;
		char			d = x;

		std::cout << "\n";

		std::cout << "int    : ";
		if (x.get_print_0() == -1)
			std::cout << "Impossible\n";
		else
			std::cout << a << "\n";

		std::cout << "float  : ";
		if (x.get_print_1() == -1)
			std::cout << "Impossible\n";
		else
			std::cout << b << "\n";

		std::cout << "double : ";
		if (x.get_print_2() == -1)
			std::cout << "Impossible\n";
		else
			std::cout << c << "\n";

		std::cout << "char   : ";
		if (x.get_print_3() == -1)
			std::cout << "Non displayable\n";
		else
			std::cout << "\'" << d << "\'" << "\n";
	}
	catch(const CastScalaire::InvalidString &e)
	{
		e.print_error();
	}
	
	return (0);
}



static int	check_error(int argc, char **argv)
{	
	(void) argv;
	if (argc != 2)
	{
		std::cerr << "\033[31;01m" << "Error : One argument required" << "\033[00m" <<  std::endl;
		return (1);
	}
	if (!argv[1])
	{
		std::cerr << "\033[31;01m" << "Error : NULL argument" << "\033[00m" <<  std::endl;
		return (1);
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
