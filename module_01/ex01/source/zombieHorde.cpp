/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:19:43 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/12 21:58:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

Zombie*	zombieHorde(int N, std::string name)
{
	int		i;
	Zombie	*new_zombie_horde;

	i = 0;
	new_zombie_horde = new Zombie[N];
	while (i < N)
	{
		new_zombie_horde[i].set_name(name);
		i++;
	}
	return (new_zombie_horde);
}
