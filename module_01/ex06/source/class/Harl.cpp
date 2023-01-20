/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/20 10:03:43 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   Constructeur															  */
/*                                                                            */
/* ************************************************************************** */
Harl::Harl(void)
{
	std::cout << "\033[00;02;03m" << "Constructeur Harl" << "\033[00m" << std::endl;
	tab_ptr_member[0] = &Harl::debug;
	tab_ptr_member[1] = &Harl::info;
	tab_ptr_member[2] = &Harl::warning;
	tab_ptr_member[3] = &Harl::error;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*   Destructeur															  */
/*                                                                            */
/* ************************************************************************** */
Harl::~Harl(void)
{
	return ;
}

/*   PUBLIC   **************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*   "__attribute__ ((fallthrough))" désactive le message d'erreur g++.		  */
/*                                                                            */
/* ************************************************************************** */
void	Harl::complain(int level)
{
	switch (level)
	{
		case 1:
		{
			(this->*tab_ptr_member[0])();
			__attribute__ ((fallthrough));
		}
		case 2:
		{
			(this->*tab_ptr_member[1])();
			__attribute__ ((fallthrough));
		}
		case 3:
			(this->*tab_ptr_member[2])();
			__attribute__ ((fallthrough));
		case 4:
			(this->*tab_ptr_member[3])();
	}
}

/*   PRIVATE   *************************************************************** */

void	Harl::debug(void)
{
	std::cout << "DEBUG" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR" << std::endl;
}
