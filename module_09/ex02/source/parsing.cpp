/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:18:40 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/25 08:59:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

int	check_error_atol(std::string &str, long int result);

std::vector<int>	*parsing(int argc, char **argv)
{
	std::vector<int> *ret = NULL;

	try
	{
		ret = new std::vector<int>();
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_BOLD_RED << e.what() << COLOR_RESET << std::endl;
		delete ret;
		return (NULL);
	}


	if (argc == 2)
	{
		std::string			line(argv[1]);
		std::istringstream	ss(line);
		std::string			stock;

		while (std::getline(ss, stock, ' '))
		{
			long int	stock_i_num;

			if (stock.empty())
				continue ;
			for (std::string :: iterator it = stock.begin(); it != stock.end(); it++)
			{
				if (!std::isdigit(*it))
				{
					std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad arguments. Not a positive integer." << COLOR_RESET << std::endl;
					delete ret;
					return (NULL);
				}
			}

			stock_i_num = std::atol(stock.c_str());

			if (check_error_atol(stock, stock_i_num))
			{
				std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad value. Int max" << COLOR_RESET << std::endl;
				delete ret;
				return (NULL);
			}
			ret->push_back(static_cast<int>(stock_i_num));
		}
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			long int	stock_i_num;
			std::string	line(argv[i]);

			if (line.empty())
				continue ;
			for (std::string :: iterator it = line.begin(); it != line.end(); it++)
			{
				if (!std::isdigit(*it))
				{
					std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad arguments. Not a positive integer." << COLOR_RESET << std::endl;
					delete ret;
					return (NULL);
				}
			}

			stock_i_num = std::atol(argv[i]);
			if (check_error_atol(line, stock_i_num))
			{
				std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad value. Int max" << COLOR_RESET << std::endl;
				delete ret;
				return (NULL);
			}
			ret->push_back(static_cast<int>(stock_i_num));
		}	
	}

	return (ret);
}

int	check_error_atol(std::string &str, long int result)
{
	if (result > 2147483647 || result < -2147483648)
		return (1);
	if (str.empty())
		return (1);
	return (0);
}

std::list<int>	*l_parsing(int argc, char **argv)
{
	std::list<int> *ret = NULL;

	try
	{
		ret = new std::list<int>();
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_BOLD_RED << e.what() << COLOR_RESET << std::endl;
		delete ret;
		return (NULL);
	}


	if (argc == 2)
	{
		std::string			line(argv[1]);
		std::istringstream	ss(line);
		std::string			stock;

		while (std::getline(ss, stock, ' '))
		{
			long int	stock_i_num;

			if (stock.empty())
				continue ;
			for (std::string :: iterator it = stock.begin(); it != stock.end(); it++)
			{
				if (!std::isdigit(*it))
				{
					std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad arguments. Not a positive integer." << COLOR_RESET << std::endl;
					delete ret;
					return (NULL);
				}
			}

			stock_i_num = std::atol(stock.c_str());

			if (check_error_atol(stock, stock_i_num))
			{
				std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad value. Int max" << COLOR_RESET << std::endl;
				delete ret;
				return (NULL);
			}
			ret->push_back(static_cast<int>(stock_i_num));
		}
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			long int	stock_i_num;
			std::string	line(argv[i]);

			if (line.empty())
				continue ;
			for (std::string :: iterator it = line.begin(); it != line.end(); it++)
			{
				if (!std::isdigit(*it))
				{
					std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad arguments. Not a positive integer." << COLOR_RESET << std::endl;
					delete ret;
					return (NULL);
				}
			}

			stock_i_num = std::atol(argv[i]);
			if (check_error_atol(line, stock_i_num))
			{
				std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad value. Int max" << COLOR_RESET << std::endl;
				delete ret;
				return (NULL);
			}
			ret->push_back(static_cast<int>(stock_i_num));
		}	
	}

	return (ret);
}