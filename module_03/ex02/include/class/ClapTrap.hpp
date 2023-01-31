/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/31 16:03:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

public:

	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &ClapTrap_src);
	~ClapTrap(void);

	ClapTrap	&operator = (const ClapTrap &right);

	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	std::string	get__name(void) const;
	int			get__energy_points(void) const;
	static void	fight(ClapTrap &attacker, ClapTrap &victim, int amount);

protected:

	const std::string	_name;
	int					_hit_points;
	int					_energy_points;
	int					_attack_damage;

private:

};

#endif
