/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:24:12 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/16 08:17:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <iomanip>
# include <header.hpp>

class HumanB
{

public:

	HumanB(void);
	HumanB(std::string name);
	~HumanB(void);

	void	attack(void) const;
	void	setWeapon(Weapon &new_W);

private:

	std::string	_name;
	Weapon		*_weapon;

};

#endif
