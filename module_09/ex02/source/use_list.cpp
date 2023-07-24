/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_list.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:04:03 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/24 21:55:35 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

static void	sort_with_list(std::list<int> *list_line);

int	use_list(std::string &line)
{
	std::list<int>	*list_line = NULL;

	list_line = l_parsing(line);
	if (!list_line)
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad arguments." << COLOR_RESET << std::endl;
		return (1);
	}
	if ((*list_line).size() == 0)
	{
		std::cerr << COLOR_BOLD_RED << "Error: bad arguments." << COLOR_RESET << std::endl;
		delete list_line;
		return (1);		
	}

	sort_with_list(list_line);

	delete list_line;

	return (0);
}

static void	sort_with_list(std::list<int> *list_line)
{
	clock_t						start;
	clock_t						end;
	double						time_taken;

	std::list<int> :: iterator	it_list_line;
	std::list<int>				S;
	std::list<int>				pend;

	start = clock();

	it_list_line = (*list_line).begin();

	l_sort_pair(it_list_line, (*list_line).end(), (*list_line).size() );

	l_recursive_sort_biggest_num_pairs(it_list_line, it_list_line, (*list_line).size() / 2, 0);

	l_build_S_pend(it_list_line, (*list_line).end(), (*list_line).size(), S, pend);

	l_insert_sort_pend(S, pend);

	show_S<std::list<int> >(S);

	end = clock();
	time_taken = (double)(end - start) / CLOCKS_PER_SEC;
	std::cout << "Temps d'exécution de" << COLOR_BOLD_RED << " list "<< COLOR_RESET << ":\t" << std::fixed << std::setprecision(6) << time_taken << " secondes" << std::endl;
}

std::list<int> :: iterator	give_it_list(std::list<int> :: iterator it, int index)
{
	for (int i = 0; i < index; i++)
		it++;
	return (it);
}
