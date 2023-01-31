/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:26:06 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/31 16:08:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:

	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &ScavTrap_src);
	~ScavTrap(void);

	ScavTrap	&operator = (const ScavTrap &right);

	void	attack(const std::string &target);
	void	guardGate(void);

protected:

private:

};

#endif
