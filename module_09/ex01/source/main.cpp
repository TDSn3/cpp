/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/18 10:24:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"
#include <header.hpp>

int	check_error_atol(std::string &str, long int result);
int	loop_str(std::string &stock);

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad numbers of arguments." << COLOR_RESET << std::endl;
		return (1);
	}

	std::string			line(argv[1]);
	std::istringstream	ss(line);
	std::string			stock;
	std::stack<int>		npf_stack;

	std::cout << line << "\n---" << std::endl;

	while (std::getline(ss, stock, ' '))
	{
		long int	stock_i_num;

		std::cout << stock << std::endl;

		if (stock.empty())
			continue ;
		if (loop_str(stock))
			return (1);
		if (stock != "+" && stock != "-" && stock != "/" && stock != "*")
		{
			stock_i_num = std::atol(stock.c_str());
			if (check_error_atol(stock, stock_i_num) || stock_i_num > 9)
			{
				std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad value" << COLOR_RESET << std::endl;
				return (1);				// Error: syntax. Bad value.
			}
			std::cout << COLOR_BOLD_RED << stock_i_num << COLOR_RESET << std::endl;
			npf_stack.push(static_cast<int>(stock_i_num));
		}
		else if (npf_stack.size() < 2)	// (npf_stack.top() == "+" || npf_stack.top() == "-" || npf_stack.top() == "/" || npf_stack.top() == "*")
		{
			std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad arguments. To many tokens." << COLOR_RESET << std::endl;
			return (1);			
		}
		else							// + - / *
		{
			int	first;
			int	second;

			second = npf_stack.top();
			npf_stack.pop();
			first = npf_stack.top();
			npf_stack.pop();

			std::cout << COLOR_BOLD_RED << first << stock << second << COLOR_RESET << std::endl;

			if (stock == "+")
			{
				npf_stack.push(first + second);
			}
			else if (stock == "-")
			{
				npf_stack.push(first - second);
			}
			else if (stock== "/")
			{
				npf_stack.push(first / second);
			}
			else if (stock == "*")
			{
				npf_stack.push(first * second);
			}
		}
	}
	std::cout << "---" << std::endl;
	if (npf_stack.size() == 1)
		std::cout << npf_stack.top() << std::endl;
	else
	{
		std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad arguments. To many numbers." << COLOR_RESET << std::endl;
		return (1);
	}

	return (0);
}

int	loop_str(std::string &stock)
{
	for (std::string::iterator it = stock.begin(); it != stock.end(); it++)
	{
		if (!std::isdigit(*it) && *it != '+' && *it != '-' && *it != '/' && *it != '*')
		{
			std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad arguments." << COLOR_RESET << std::endl;
			return (1);	// Error: syntax. Bad arguments.
		}
		if (*it == '+' || *it == '/' || *it == '*')
		{
			if (stock.size() != 1)
			{
				std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad arguments." << COLOR_RESET << std::endl;
				return (1);
			}
		}
		if (*it == '-' && stock.size() != 1 && it != stock.begin())
		{
			std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad arguments." << COLOR_RESET << std::endl;
			return (1);				
		}
	}
	return (0);
}

int	check_error_atol(std::string &str, long int result)
{
	if (result > 2147483647 || result < -2147483648)
		return (1);
	if (str.empty())
		return (1);
	return (0);
}
