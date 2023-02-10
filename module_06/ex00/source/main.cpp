/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/10 09:15:06 by tda-silv         ###   ########.fr       */
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

// char || int || float || double

int main(void)
{
	CastScalaire	a(42.0f);
	int				b = a;
	float			c = a;
	double			d = a;
	char			e = a;

	std::cout << b << "\n" << c << "\n" << d  << "\n" << e << std::endl;
	return (0);
}

//static void	wait_return(void)
//{
//	std::cout << "\033[00;02;03m"
//	<< "Press any key to continue"
//	<< "\033[00m" << std::endl;
//	std::cin.get();
//}
