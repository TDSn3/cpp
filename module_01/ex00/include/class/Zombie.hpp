/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/12 15:45:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

/* ************************************************************************** */

# ifndef INLCUDE_GUARD
#  define INLCUDE_GUARD

#  include <iostream>
#  include <iomanip>

# endif

/* ************************************************************************** */

class Zombie
{

public:

	Zombie(void);
	~Zombie(void);

	void	announce(void);
	Zombie*	newZombie(std::string name);
	void	randomChump(std::string name);

private:

	std::string _name;

};

#endif
