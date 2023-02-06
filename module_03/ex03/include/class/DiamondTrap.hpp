/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:05:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/06 16:00:40 by tda-silv         ###   ########.fr       */
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

	using		ScavTrap::attack;
	void		whoAmI(void);
	std::string	get__name(void) const;

protected:

private:

	const std::string	_name;

};

#endif
