/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:03:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/12 21:03:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

Zombie	*newZombie(std::string const name)
{
	Zombie	*new_zombie;

	new_zombie = new Zombie(name);
	return (new_zombie);
}
