/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/12 20:31:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static Zombie	*newZombie(std::string const name);
static void	randomChump(std::string const name);

int	main(void)
{
	Zombie	*zombie_heap_1;
	Zombie	*zombie_heap_2;
	Zombie	*zombie_heap_3;

	randomChump("zombie_stack_1");
	randomChump("zombie_stack_2");
	randomChump("zombie_stack_3");

	zombie_heap_1 = newZombie("zombie_heap_1");
	zombie_heap_2 = newZombie("zombie_heap_2");
	zombie_heap_3 = newZombie("zombie_heap_3");

	std::cout << std::endl;

	std::cout << "\033[30m" << "zombie_heap_1 created" << "\033[00m" << std::endl;
	std::cout << "\033[30m" << "zombie_heap_2 created" << "\033[00m" << std::endl;
	std::cout << "\033[30m" << "zombie_heap_3 created" << "\033[00m" << std::endl;

	std::cout << "\nDO SOMETING...\n" << std::endl;

	delete zombie_heap_1;
	delete zombie_heap_2;
	delete zombie_heap_3;

	return (0);
}

static Zombie	*newZombie(std::string const name)
{
	Zombie	*new_zombie;

	new_zombie = new Zombie(name);
	return (new_zombie);
}

static void	randomChump(std::string const name)
{
	Zombie	new_zombie(name);

	new_zombie.announce();
}
