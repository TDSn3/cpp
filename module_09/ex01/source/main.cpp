/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/17 17:25:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"
#include <header.hpp>

int	check_error_atol(std::string str, long int result);

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad numbers of arguments." << COLOR_RESET << std::endl;
		return (1);
	}

	std::string				line(argv[1]);
	std::istringstream		ss(line);
	std::string				stock;
	std::stack<std::string>	temp_npf_stack;
	std::stack<std::string>	npf_stack;

	while (std::getline(ss, stock, ' '))
	{
		long int	stock_i_num;

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
		stock_i_num = std::atol(stock.c_str());
		if (check_error_atol(stock, stock_i_num) || stock_i_num > 9)
		{
			std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad value" << COLOR_RESET << std::endl;
			return (1);		// Error: syntax. Bad value.
		}
		temp_npf_stack.push(stock);
	}

	while (!temp_npf_stack.empty())	// reverse stack
	{
		npf_stack.push(temp_npf_stack.top());
		temp_npf_stack.pop();
	}

	std::stack<int>	npf_i_stack;

	while (!npf_stack.empty())
	{
		int	first;
		int	second;
		
		std::cout << npf_stack.top() << std::endl;
		if ((npf_stack.top() == "+" || npf_stack.top() == "-" || npf_stack.top() == "/" || npf_stack.top() == "*") && (npf_i_stack.empty() || npf_i_stack.size() < 2))
		{
			std::cerr << COLOR_BOLD_RED << "Error: syntax. Bad arguments. Impossible to continue the operation." << COLOR_RESET << std::endl;
			return (1);
		}

		first = npf_i_stack.top();
		npf_i_stack.pop();
		second = npf_i_stack.top();

		if (npf_stack.top() == "+")
		{
			npf_i_stack.push(first + second);
		}
		else if (npf_stack.top() == "-")
		{
			npf_i_stack.push(first - second);
		}
		else if (npf_stack.top() == "/")
		{
			npf_i_stack.push(first / second);
		}
		else if (npf_stack.top() == "*")
		{
			npf_i_stack.push(first * second);
		}
		else
		{
			npf_i_stack.push( std::atoi( npf_stack.top().c_str() ) );
		}
		npf_stack.pop();
	}

	return (0);
}

int	check_error_atol(std::string str, long int result)
{
	if (result > 2147483647 || result < -2147483648)
		return (1);
	if (str.empty())
		return (1);
	return (0);
}
