/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_vector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:04:03 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/25 09:24:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

static void	sort_with_vector(std::vector<int> *vect_line);

int	use_vector(int argc, char **argv)
{
	std::vector<int>	*vect_line = NULL;

	vect_line = parsing(argc, argv);
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

	std::cout << COLOR_MAGENTA << "Non trié :\t"<< COLOR_RESET;
	show_S<std::vector<int> >(*vect_line);

	start = clock();

	it_vect_line = (*vect_line).begin();

	sort_pair(it_vect_line, (*vect_line).end(), (*vect_line).size() );

	recursive_sort_biggest_num_pairs(it_vect_line, it_vect_line, (*vect_line).size() / 2, 0);

	build_S_pend(it_vect_line, (*vect_line).end(), (*vect_line).size(), S, pend);

	insert_sort_pend(S, pend);

	std::cout << COLOR_BOLD_MAGENTA << "Trié :\t\t"<< COLOR_RESET;
	show_S<std::vector<int> >(S);

	end = clock();
	time_taken = (double)(end - start) / CLOCKS_PER_SEC;
	std::cout << "Temps d'exécution de" << COLOR_BOLD_MAGENTA << " vector "<< COLOR_RESET << ":\t" << std::fixed << std::setprecision(6) << time_taken << " secondes\n" << std::endl;
}
