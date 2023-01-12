/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:36 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/12 21:07:29 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/* ************************************************************************** */

# ifndef INCLUDE_GUARD
#  define INCLUDE_GUARD

#  include <iostream>
#  include <iomanip>

# endif

/* ************************************************************************** */

# include "./class/Zombie.hpp"

/* ************************************************************************** */

Zombie	*newZombie(std::string const name);
void	randomChump(std::string const name);

#endif
