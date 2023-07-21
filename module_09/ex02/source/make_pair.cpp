/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:02:58 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/21 10:21:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.hpp"
#include <header.hpp>

//void	sort_pair(std::vector<std::vector<int> * > *vect_list_pair);

std::vector<std::vector<int> * >	*make_pair(std::vector<int> *vect)
{
	std::vector<std::vector<int> * >	*vect_list_pair;
	std::vector<int> 					*p_vect_pair;
	size_t								i;

	i = 0;
	p_vect_pair = NULL;
	vect_list_pair = NULL;

	try
	{
		vect_list_pair = new std::vector<std::vector<int> * >;
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_BOLD_RED << e.what() << COLOR_RESET << std::endl;
		delete vect_list_pair;
		return (NULL);
	}

	for (std::vector<int>::iterator it = vect->begin(); it != vect->end(); it++)
	{
		if (i == 0)	// [0]
		{			
			try
			{
				p_vect_pair = new std::vector<int>(2, -1);
			}
			catch(const std::exception& e)
			{
				std::cerr << COLOR_BOLD_RED << e.what() << COLOR_RESET << std::endl;
				delete p_vect_pair;

				for (std::vector<std::vector<int> * >::iterator it2 = vect_list_pair->begin(); it2 != vect_list_pair->end(); it2++)
				{
					if (*it2)
					{
						delete *it2;
						*it2 = NULL;
					}
				}

				delete vect_list_pair;
				return (NULL);
			}

			(*p_vect_pair)[0] = *it;

			if (it + 1 == vect->end())
				vect_list_pair->push_back(p_vect_pair);
			
			i++;
		}
		else		// [1]
		{
			(*p_vect_pair)[1] = *it;
			vect_list_pair->push_back(p_vect_pair);

			p_vect_pair = NULL;

			i = 0;
		}
	}

	std::cout << "Make pair sorted :" << std::endl ;

	//sort_pair(vect_list_pair);

	for (std::vector<std::vector<int> * >::iterator it = vect_list_pair->begin(); it != vect_list_pair->end(); it++)
	{
		for (std::vector<int>::iterator it2 = (*it)->begin(); it2 != (*it)->end(); it2++)
		{
			if (*it2 >= 0)
				std::cout << "[" << *it2 << "] " ;
		}
		std::cout << std::endl ;
	}
	
	return (vect_list_pair);
}

//void	sort_pair(std::vector<std::vector<int> * > *vect_list_pair)
//{
//	for (std::vector<std::vector<int> * >::iterator it = vect_list_pair->begin(); it != vect_list_pair->end(); it++)
//	{
//		if ( (*(*it))[1] >= 0)
//		{
//			if ( (*(*it))[0] > (*(*it))[1])
//			{
//				int	stock;
				
//				stock = (*(*it))[0];
//				(*(*it))[0] = (*(*it))[1];
//				(*(*it))[1] = stock;
//			}
//		}
//	}	
//}
