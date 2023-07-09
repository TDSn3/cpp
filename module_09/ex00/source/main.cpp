/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/09 17:26:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"
#include <header.hpp>

int	read_file(std::ifstream &file);
int	split_line(std::string &line);
void print_error(int err);

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: bad numbers of arguments." << std::endl;
		return (1);
	}

	std::ifstream						file(argv[1]);

	if (!file.is_open() || read_file(file))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	file.close();

	return (0);
}

int	read_file(std::ifstream &file)
{	
	unsigned int		i;
	std::string			line;
	std::string			stock;

	i = 0;
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;

		if (i == 0 && line == "date | value")
			continue ;
		print_error(split_line(line));
		i++;
	}
	return (0);
}

void print_error(int err)
{
	if (err)
	{
		if (err == 1)
			std::cerr << "Error: syntax. More or minus than 3 args." << std::endl;
		else if (err == 2)
			std::cerr << "Error: syntax. Not a pipe." << std::endl;
		else if (err == 3)
			std::cerr << "Error: syntax. Bad date format. YYYY/MM/DD." << std::endl;
		else if (err == 4)
			std::cerr << "Error: syntax. Bad value of btc." << std::endl;
	}
}

int	split_line(std::string &line)
{
	unsigned int		i;
	unsigned int		j;
	std::string			stock_line;
	std::istringstream	ss(line);

	i = 0;
	j = 0;
	while (std::getline(ss, stock_line, ' '))
	{
		std::cout << stock_line << std::endl;

		if (i == 0)			// date
		{
			// int					stock_i_date;
			std::string			stock_date;
			std::istringstream	ss2(stock_line);

			while (std::getline(ss2, stock_date, '-'))
			{
				size_t	k;

				std::cout << "date: " << stock_date << std::endl;

				for (k = 0; stock_date[k]; k++)
					if (!std::isdigit(stock_date[k]))
						return (3);			// Error: syntax. Bad date format. YYYY/MM/DD.
				if (j == 0 && k != 4)		// year
					return (3);				// Error: syntax. Bad date format. YYYY/MM/DD.
				else if (j > 0 && k != 2)	// month/day
					return (3);				// Error: syntax. Bad date format. YYYY/MM/DD.
				// stock_i_date = std::stoi(stock_date);

				j++;
			}
			if (j != 3)
				return (3);	// Error: syntax. Bad date format. YYYY/MM/DD.
		}
		else if (i == 1)	// pipe
		{
			if (stock_line != "|")
				return (2);	// Error: syntax. Not a pipe.
		}
		else if (i == 2)	//value
		{
			size_t	k;
			
			std::cout << "value: " << stock_line << std::endl;
			for (k = 0; stock_line[k]; k++)
				if (!std::isdigit(stock_line[k]))
					return (4);	// Error: syntax. Bad value of btc.
		}
		i++;
	}
	if (i != 3)
		return (1);	// Error: syntax. More or minus than 3 args.
	return (0);
}
