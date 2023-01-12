/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/12 19:41:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

/* ************************************************************************** */

# ifndef INCLUDE_GUARD
#  define INCLUDE_GUARD

#  include <iostream>
#  include <iomanip>

# endif

/* ************************************************************************** */

class Zombie
{

public:

	Zombie(std::string const name);
	~Zombie(void);

	void	announce(void) const;

private:

	std::string const	_name;

};

#endif
