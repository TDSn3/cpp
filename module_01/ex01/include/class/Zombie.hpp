/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/13 10:46:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>

class Zombie
{

public:

	Zombie(void);
	~Zombie(void);

	void	announce(void) const;
	void	set_name(std::string const name);

private:

	std::string	_name;

};

#endif
