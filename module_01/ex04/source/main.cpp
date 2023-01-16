/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/16 16:17:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

static int	check_error(int argc, char **argv);

int main(int argc, char **argv)
{
	if (check_error(argc, argv))
		return (1);

	std::string		file_name(argv[1]);
	std::string		search_this(argv[2]);
	std::string		replace_by(argv[3]);
	std::string		stock_line;
	std::ifstream	ifs(file_name);
	int				pos;

	if (!ifs.is_open())
	{
		std::cout << "File not open" << std::endl;
		return (1);
	}

	std::ofstream	ofs(file_name.append(".replace"));

	if (!ofs.is_open())
	{
		std::cout << "File not open" << std::endl;
		return (1);
	}

	while (ifs.is_open() && std::getline(ifs, stock_line))
	{
		pos = stock_line.find(search_this);
		while (pos != -1)
		{
			if (pos != -1)
			{
				stock_line.erase(pos, search_this.size());
				stock_line.insert(pos, replace_by);
			}
			pos = stock_line.find(search_this);
		}
		ofs << stock_line;
		if (!ifs.eof())
			ofs << "\n";
	}

	ifs.close();
	ofs.close();
	return (0);
}

static int	check_error(int argc, char **argv)
{
	if (argc != 4
		|| !argv[1] || !argv[1][0]
		|| !argv[2] || !argv[2][0])
		return (1);
	return (0);
}
