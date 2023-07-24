/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_vector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:04:03 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 20:09:16 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

static void	sort_with_vector(std::vector<int> *vect_line);

int	use_vector(std::string &line)
{
	std::vector<int>	*vect_line = NULL;

	vect_line = parsing(line);
	if (!vect_line)
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad arguments." << COLOR_RESET << std::endl;
		return (1);
	}
	if ((*vect_line).size() == 0)
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad arguments." << COLOR_RESET << std::endl;
		delete vect_line;
		return (1);		
	}

	sort_with_vector(vect_line);

	delete vect_line;

	return (0);
}

static void	sort_with_vector(std::vector<int> *vect_line)
{
	clock_t							start;
	clock_t							end;
	double							time_taken;

	std::vector<int> :: iterator	it_vect_line;
	std::vector<int>				S;
	std::vector<int>				pend;

	start = clock();

	it_vect_line = (*vect_line).begin();

	sort_pair(it_vect_line, (*vect_line).end(), (*vect_line).size() );

	recursive_sort_biggest_num_pairs(it_vect_line, it_vect_line, (*vect_line).size() / 2, 0);

	build_S_pend(it_vect_line, (*vect_line).end(), (*vect_line).size(), S, pend);

	insert_sort_pend(S, pend);

	show_S(S);

	end = clock();
	time_taken = (double)(end - start) / CLOCKS_PER_SEC;
	std::cout << "Temps d'exécution : " << std::fixed << std::setprecision(6) << time_taken << " secondes" << std::endl;
}
