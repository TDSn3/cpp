/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:36 by tda-silv          #+#    #+#             */
/*   Updated: 2023/07/21 09:43:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

# include <cstdlib>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cctype>
# include <memory>
# include <vector>
# include <exception>

# include "colors.hpp"
# include "./class/Pair_it.hpp"

std::vector<int>					*parsing(std::string &line);
std::vector<std::vector<int> * >	*make_pair(std::vector<int> *vect);

#endif
