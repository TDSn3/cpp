/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/10 22:02:54 by tda-silv         ###   ########.fr       */
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

// char || int || float || double

int main(int argc, char **argv)
{
	if (check_error(argc, argv))
		return (1);

	CastScalaire	a(argv[1]);
//	CastScalaire	a("nan");
//	int				b = a;
//	float			c = a;
//	double			d = a;
//	char			e = a;
//	std::string		f = a;
//
//	std::cout << b << "\n" << c << "\n" << d  << "\n" << f << "\n" << e << std::endl;
	return (0);
}

static int	check_error(int argc, char **argv)
{	
	(void) argv;
	if (argc != 2)
	{
		std::cout << "\033[31;01m" << "Error : One argument required." << "\033[00m" <<  std::endl;
		return (1);
	}
	if (!argv[1])
	{
		std::cout << "\033[31;01m" << "Error : wrong argument." << "\033[00m" <<  std::endl;
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
