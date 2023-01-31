/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:05:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/31 20:42:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public virtual ClapTrap, public FragTrap, public ScavTrap
{

public:

	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &DiamondTrap_src);
	~DiamondTrap(void);

	DiamondTrap	&operator = (const DiamondTrap &right);

	void	whoAmI(void);

protected:

private:

	const std::string	_name;

};

#endif
