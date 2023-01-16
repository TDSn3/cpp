/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/16 07:43:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <iomanip>

class Weapon
{

public:

	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);

	const std::string	&getType(void) const;
	void				setType(std::string name);

private:

	std::string	type;

};

#endif
