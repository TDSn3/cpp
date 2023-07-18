/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/18 09:42:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"
#include <header.hpp>

int		read_file(std::ifstream &file, std::map<int, double> &db_input);
int		split_line(std::string &line, std::map<int, double> &db_input);
bool	check_date(int year, int month, int day);
int		read_data_csv(std::map<int, double> &db_data_csv);
int		split_line_csv(std::ifstream &file, std::map<int, double> &db_data_csv);
void	put_date_cout(int date);
void	print_error(int err);

int		main(int argc, char **argv)
{
	std::map<int, double>	db_input;
	std::map<int, double>	db_data_csv;

	if (argc != 2 || !argv[1])
	{
		std::cerr << "Error: bad numbers of arguments." << std::endl;
		return (1);
	}

	std::ifstream						file(argv[1]);

	if (!file.is_open() || read_file(file, db_input))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	file.close();

	read_data_csv(db_data_csv);

	std::cout << "\n\n" << std::endl;

	for (std::map<int, double>::iterator it = db_input.begin(); it != db_input.end(); it++)
	{		
		std::map<int, double>::iterator	stock_it_lower_bound;

		stock_it_lower_bound = db_data_csv.lower_bound(it->first);
		if (stock_it_lower_bound->first != it->first && stock_it_lower_bound != db_data_csv.begin())
			stock_it_lower_bound--;

		put_date_cout(it->first);
		std::cout << " | " << it->second << " btc" << "\n";

		std::cout << COLOR_BOLD_MAGENTA;
		put_date_cout(stock_it_lower_bound->first);
		std::cout << " | " << stock_it_lower_bound->second << " $";
		std::cout << COLOR_RESET << "\n";
		std::cout << "          -> ";
		std::cout << it->second * stock_it_lower_bound->second << "\n" << std::endl;
	}

	return (0);
}

int		read_file(std::ifstream &file, std::map<int, double> &db_input)
{
	unsigned int		i;
	std::string			line;
	std::string			stock;

	i = 0;
	while (std::getline(file, line))
	{
		if (line.size() != 0)
			std::cout << line << std::endl;

		if ((i == 0 && line == "date | value") || line.size() == 0)
		{
			i++;
			continue ;
		}
		print_error(split_line(line, db_input));
		i++;
	}
	return (0);
}

void	print_error(int err)
{
	if (err)
	{
		std::cerr << COLOR_BOLD_RED;
		if (err == 1)
			std::cerr << "Error: syntax. More or minus than 3 args.";
		else if (err == 2)
			std::cerr << "Error: syntax. Not a pipe.";
		else if (err == 3)
			std::cerr << "Error: syntax. Bad date format. YYYY-MM-DD.";
		else if (err == 4)
			std::cerr << "Error: syntax. Bad value of btc.";
		else if (err == 5)
			std::cerr << "Error: syntax. Bad value of date.";
		std::cerr << COLOR_RESET << "\n" << std::endl;
	}
}

int		split_line(std::string &line, std::map<int, double> &db_input)
{
	unsigned int		i;
	unsigned int		j;
	int					tab_date[3];
	double				stock_d_value;
	std::string			stock_line;
	std::istringstream	ss(line);

	i = 0;
	j = 0;
	while (std::getline(ss, stock_line, ' '))
	{
		if (i == 0)							// date
		{
			long int			stock_i_date;
			std::string			stock_date;
			std::istringstream	ss2(stock_line);

			while (std::getline(ss2, stock_date, '-'))
			{
				size_t	k;

				for (k = 0; stock_date[k]; k++)
					if (!std::isdigit(stock_date[k]))
						return (3);			// Error: syntax. Bad date format. YYYY-MM-DD.
				if (j == 0 && k != 4)		// year
					return (3);				// Error: syntax. Bad date format. YYYY-MM-DD.
				else if (j > 0 && k != 2)	// month/day
					return (3);				// Error: syntax. Bad date format. YYYY-MM-DD.
				stock_i_date = std::atol(stock_date.c_str());
				if (check_error_atol(stock_date, stock_i_date))
					return (5);				// Error: syntax. Bad value of date.
				if (j < 3)
					tab_date[j] = static_cast<int>(stock_i_date);
				j++;
			}
			if (j != 3)
				return (3);					// Error: syntax. Bad date format. YYYY-MM-DD.
		}
		else if (i == 1)					// pipe
		{
			if (stock_line != "|")
				return (2);	// Error: syntax. Not a pipe.
		}
		else if (i == 2)					// value
		{
			size_t	k;
			
			for (k = 0; stock_line[k]; k++)
				if (!std::isdigit(stock_line[k]) && stock_line[k] != '.')
					return (4);				// Error: syntax. Bad value of btc.
			stock_d_value = std::atof(stock_line.c_str());
			if (check_error_atof(stock_line, stock_d_value))
				return (4);					// Error: syntax. Bad value of btc.
			if (stock_d_value < 0 || stock_d_value > 1000)
				return (4);					// Error: syntax. Bad value of btc.
		}
		i++;
	}
	if (i != 3)
		return (1);							// Error: syntax. More or minus than 3 args.
	if (!check_date(tab_date[0], tab_date[1], tab_date[2]))
		return (5);							// Error: syntax. Bad value of date.
	db_input[(tab_date[0] * 10000) + (tab_date[1] * 100) + tab_date[2]] = stock_d_value;
	std::cout << COLOR_BOLD_MAGENTA;
	std::cout << (tab_date[0] * 10000) + (tab_date[1] * 100) + tab_date[2] << " " << stock_d_value << "\n";
	std::cout << COLOR_RESET << std::endl;
	return (0);
}

bool 	check_leap_year(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool 	check_date(int year, int month, int day)
{
	int	day_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month < 1 || month > 12 || day < 1)
		return false;

	if (check_leap_year(year))
		day_month[1] = 29;

	return (day <= day_month[month - 1]);
}

int		read_data_csv(std::map<int, double> &db_data_csv)
{
	std::ifstream	file("source/data.csv");

	if (!file.is_open() || split_line_csv(file, db_data_csv))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	file.close();

	return (0);
}

int		split_line_csv(std::ifstream &file, std::map<int, double> &db_data_csv)
{
	unsigned int		i;
	unsigned int		j;
	int					tab_date[3];
	double				stock_d_value;
	std::string			line;
	std::string			stock;

	i = 0;
	j = 0;
	while (std::getline(file, line))
	{
		if (i == 0 && line == "date,exchange_rate")
		{
			i++;
			continue ;
		}
		
		std::istringstream	ss(line);

		while (std::getline(ss, stock, ','))
		{
			if (j == 0)			// date
			{
				int					k;
				int					stock_i_date;
				std::string			stock_date;
				std::istringstream	ss2(stock);

				k = 0;
				while (std::getline(ss2, stock_date, '-'))
				{
					stock_i_date = std::atoi(stock_date.c_str());
					tab_date[k] = stock_i_date;
					k++;
				}
			}
			else if (j == 1)	// value
			{
				stock_d_value = std::atof(stock.c_str());
			}
			j++;
		}
		j = 0;
		db_data_csv[(tab_date[0] * 10000) + (tab_date[1] * 100) + tab_date[2]] = stock_d_value;
		i++;
	}
	return (0);
}

void	put_date_cout(int date)
{
	int	y;
	int	m;
	int	d;

	y = date / 10000;
	m = (date / 100) % 100;
	d = date % 100;
	std::cout << y << "-";
	if (m < 10)
		std::cout << "0";
	std::cout << m << "-";
	if (d < 10)
		std::cout << "0";
	std::cout << d;
}
