/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastScalaire.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:00:45 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/11 10:48:07 by tda-silv         ###   ########.fr       */
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

	_index[0] = 0;
	_index[1] = 0;
	_index[2] = 0;
	_index[3] = 0;

	switch (if_int(arg))
	{
	case 1:
		std::cout << "Int detected" << std::endl;
		break ;
	default:
		switch (if_float(arg))
		{
		case 1:
			std::cout << "Float detected" << std::endl;
			break ;
		default:
			switch (if_double(arg))
			{
			case 1:
				std::cout << "Double detected" << std::endl;
				break ;	
			default:
				break ;
			}
		}
	}
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

int	CastScalaire::check_one_point_float(char *arg) const
{
	int	count = 0;

	for (int i = 0; arg[i]; i++)
		if (arg[i] == '.')
			count++;
	if (count == 1)
		return (1);
	return (0);
}

int	CastScalaire::if_int(char *arg)
{
	char	*endptr;
	long	stock_l;

	stock_l = std::strtol(arg, &endptr, 10);  				// long (int)
	if (endptr == arg + std::string(arg).size())
	{
		_index[0] = 1;										// -> This is an int
		_stock_data = reinterpret_cast < __int64_t &> (stock_l);
		return (1);
	}
	return (0);
}

int	CastScalaire::if_float(char *arg)
{
	char	*endptr;
	float	stock_f;

	stock_f = std::strtof(arg, &endptr);					// float
	if (endptr != NULL && endptr != arg
		&& std::string(endptr).size () == 1
		&& std::string(endptr) == "f"
		&& endptr == arg + std::string(arg).size() - 1)	
	{
		if (check_one_point_float(arg))
		{
			_index[1] = 1;									// -> This is a float with f
			_stock_data = reinterpret_cast<__int64_t&>(stock_f);
			return (1);
		}
	}
	return (0);
}

int	CastScalaire::if_double(char *arg)
{
	char	*endptr;
	double	stock_d;

	stock_d = std::strtod(arg, &endptr);					// double
	if (endptr == arg + std::string(arg).size())
	{
		_index[2] = 1;										// -> This is a double
		_stock_data = reinterpret_cast<__int64_t&>(stock_d);
		print_bits();
		return (1);
	}
	return (0);
}

void	CastScalaire::print_bits(void) const
{
	for (int i = 63; i >= 0; i--)
	{
		std::cout << ((_stock_data >> i) & 1);
		if ((i + 1) % 8 == 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

/* ************************************************************************** */
