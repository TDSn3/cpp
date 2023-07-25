/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/25 09:14:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad numbers of arguments." << COLOR_RESET << std::endl;
		return (1);
	}

	if (use_vector(argc, argv) || use_list(argc, argv))
		return (1);

	return (0);
}
