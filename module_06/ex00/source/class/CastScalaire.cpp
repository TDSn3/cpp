/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastScalaire.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:00:45 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/10 22:21:15 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
CastScalaire::CastScalaire(char *arg)
{
	std::cout << "\033[00;02;03m" << "CastScalaire : Char* constructor called" << "\033[00m" << std::endl;

	char	*endptr;
	long	stock_l;
	float	stock_f;
	double	stock_d;

	stock_l = std::strtol(arg, &endptr, 10);
	if (*endptr != '\0')
		std::cout << "Int max" << '\n';
	if (endptr == arg + std::string(arg).size())
	{
		std::cout << "This is an int" << '\n';
	}

	stock_f = std::strtof(arg, &endptr);
	if (endptr == arg + std::string(arg).size())
	{
		std::cout << "This is a float without f" << '\n';
	}
	else if (endptr != arg
		&& std::string(endptr).size () == 1
		&& std::string(endptr) == "f"
		&& endptr == arg + std::string(arg).size() - 1)
	{
		int	count = 0;

		for (int i = 0; arg[i]; i++)
			if (arg[i] == '.')
				count++;
		if (count == 1)
			std::cout << "This is a float with f" << '\n';
	}

	stock_d = std::strtod(arg, &endptr);
	if (endptr == arg + std::string(arg).size())
	{
		std::cout << "This is a double" << '\n';
	}

	(void)stock_l;
	(void)stock_f;
	(void)stock_d;
}


/*   COPY CONSTRUCTEUR   **************************************************** */
 
CastScalaire::CastScalaire(const CastScalaire &src)
{
	std::cout << "\033[32;02;03m" << "CastScalaire : Copy constructor called" << "\033[00m" << std::endl;
	(void) src;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
CastScalaire::~CastScalaire(void)
{
	std::cout << "\033[31;01m" << "CastScalaire : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

CastScalaire	&CastScalaire::operator = (const CastScalaire &right)
{
	std::cout << "\033[33;02;03m" << "CastScalaire : Copy assignment operator called" << "\033[00m" << std::endl;
	(void) right;
	return (*this);
}

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
