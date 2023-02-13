/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastScalaire.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:00:45 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/13 12:50:53 by tda-silv         ###   ########.fr       */
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

	_print[0] = 0;
	_print[1] = 0;
	_print[2] = 0;
	_print[3] = 0;

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
				switch (if_char(arg))
				{
				case 1:
					std::cout << "Char detected" << std::endl;
					break;
				default:
					throw (InvalidString());
					break;
				}
			}
		}
	}
}


/*   COPY CONSTRUCTEUR   **************************************************** */
 
CastScalaire::CastScalaire(const CastScalaire &src)
{
	std::cout << "\033[32;02;03m" << "CastScalaire : Copy constructor called" << "\033[00m" << std::endl;
	(*this) = src;
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

	_index[0] = right._index[0];
	_index[1] = right._index[1];
	_index[2] = right._index[2];
	_index[3] = right._index[3];

	_print[0] = right._print[0];
	_print[1] = right._print[1];
	_print[2] = right._print[2];
	_print[3] = right._print[3];

	_stock_data = right._stock_data;
	_stock_arg = right._stock_arg;
	return (*this);
}

CastScalaire::operator int(void)
{
//	if (_stock_data > INT_MAX || _stock_data < INT_MIN)		//
//		_print[0] = -1;										//

	if (_index[0] == 1 && (_stock_data > INT_MAX || _stock_data < INT_MIN))
		_print[0] = -1;
	else if (_index[1] == 1 && (static_cast<long long int>(reinterpret_cast<float&>(_stock_data)) > INT_MAX || static_cast<long long int>(reinterpret_cast<float&>(_stock_data)) < INT_MIN))
		_print[0] = -1;
	else if (_index[2] == 1 && (static_cast<long long int>(reinterpret_cast<double&>(_stock_data)) > INT_MAX || static_cast<long long int>(reinterpret_cast<double&>(_stock_data)) < INT_MIN))
		_print[0] = -1;
	else if (_index[3] == 1 && (static_cast<long long int>(reinterpret_cast<char&>(_stock_data)) > INT_MAX || static_cast<long long int>(reinterpret_cast<char&>(_stock_data)) < INT_MIN))
		_print[0] = -1;

	if (_index[0] == 1)
		return (static_cast<int>(reinterpret_cast<int&>(_stock_data)));
	else if (_index[1] == 1)
		return (static_cast<int>(reinterpret_cast<float&>(_stock_data)));
	else if (_index[2] == 1)
		return (static_cast<int>(reinterpret_cast<double&>(_stock_data)));
	else if (_index[3] == 1)
		return (static_cast<int>(reinterpret_cast<char&>(_stock_data)));
	return (0);
}

CastScalaire::operator float(void)
{
	if (_index[0] == 1)
		return (static_cast<float>(reinterpret_cast<int&>(_stock_data)));
	else if (_index[1] == 1)
		return (static_cast<float>(reinterpret_cast<float&>(_stock_data)));
	else if (_index[2] == 1)
		return (static_cast<float>(reinterpret_cast<double&>(_stock_data)));
	else if (_index[3] == 1)
		return (static_cast<float>(reinterpret_cast<char&>(_stock_data)));
	return (0);
}

CastScalaire::operator double(void)
{
	if (_index[0] == 1)
		return (static_cast<double>(reinterpret_cast<int&>(_stock_data)));
	else if (_index[1] == 1)
		return (static_cast<double>(reinterpret_cast<float&>(_stock_data)));
	else if (_index[2] == 1)
		return (static_cast<double>(reinterpret_cast<double&>(_stock_data)));
	else if (_index[3] == 1)
		return (static_cast<double>(reinterpret_cast<char&>(_stock_data)));
	return (0);
}

CastScalaire::operator char(void)
{
//	if (!std::isprint(static_cast<char>(_stock_data)))	//
//		_print[3] = -1;									//

	if (((_index[0] == 1
		&& (static_cast<int>(reinterpret_cast<int&>(_stock_data)) < 0
		|| static_cast<int>(reinterpret_cast<int&>(_stock_data)) > 256))
		|| (_index[0] == 1
		&& !std::isprint(static_cast<int>(reinterpret_cast<int&>(_stock_data))))))
		_print[3] = -1;
	else if (((_index[1] == 1
		&& (static_cast<int>(reinterpret_cast<float&>(_stock_data)) < 0
		|| static_cast<int>(reinterpret_cast<float&>(_stock_data)) > 256))
		|| (_index[1] == 1
		&& !std::isprint(static_cast<int>(reinterpret_cast<float&>(_stock_data))))))
		_print[3] = -1;
	else if (((_index[2] == 1
		&& (static_cast<int>(reinterpret_cast<double&>(_stock_data)) < 0
		|| static_cast<int>(reinterpret_cast<double&>(_stock_data)) > 256))
		|| (_index[2] == 1
		&& !std::isprint(static_cast<int>(reinterpret_cast<double&>(_stock_data))))))
		_print[3] = -1;
	else if (_index[3] == 1 && (!std::isprint(static_cast<char>(_stock_data))))
		_print[3] = -1;

	if (_index[0] == 1)
		return (static_cast<char>(reinterpret_cast<int&>(_stock_data)));
	else if (_index[1] == 1)
		return (static_cast<char>(reinterpret_cast<float&>(_stock_data)));
	else if (_index[2] == 1)
		return (static_cast<char>(reinterpret_cast<double&>(_stock_data)));
	else if (_index[3] == 1)
		return (static_cast<char>(reinterpret_cast<char&>(_stock_data)));
	return (0);
}

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

void	CastScalaire::InvalidString::print_error(void) const
{
	std::cerr << "CastScalaire : Invalid string" << std::endl;
}

int				CastScalaire::get_print_0(void) const
{
	return (_print[0]);
}

int				CastScalaire::get_print_1(void) const
{
	return (_print[1]);
}

int				CastScalaire::get_print_2(void) const
{
	return (_print[2]);
}

int				CastScalaire::get_print_3(void) const
{
	return (_print[3]);
}

/* static */void	CastScalaire::print_arg(CastScalaire x)
{
	int		a = x;
	float	b = x;
	double	c = x;
	char	d = x;

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
	char		*endptr;
	long long	stock_l;

	stock_l = std::strtoll(arg, &endptr, 10);  				// long long (int)
	if (endptr == arg + std::string(arg).size())
	{
		_index[0] = 1;										// -> This is an int
		_stock_data = reinterpret_cast < __int64_t &> (stock_l);
		print_bits();
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
			print_bits();
			return (1);
		}
	}
	if (if_string(arg))										// float
		return (1);
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

int	CastScalaire::if_string(char *arg)
{
	if (   std::string(arg) == "-inff"						// double
		|| std::string(arg) == "+inff"						//
		|| std::string(arg) == "nanf")						//
	{
		_index[1] = 1;										// -> This is a float with f
		_index[3] = 1;										// -> To print the right value
		_stock_arg = arg;
		_stock_data = 0;
		return (1);
	}
	return (0);
}

int	CastScalaire::if_char(char *arg)
{	
	if (arg && std::string(arg).size() == 1)
	{
		if (std::isprint(arg[0]))
		{
			_stock_data = reinterpret_cast<__int64_t&>(arg[0]);
			_stock_data = _stock_data << 56;
			_stock_data = _stock_data >> 56;
			_index[3] = 1;
			print_bits();
			return (1);
		}
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
