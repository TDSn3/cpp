/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:24:12 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/16 08:10:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <iomanip>
# include <header.hpp>

class HumanA
{

public:

	HumanA(std::string name, Weapon &new_W);
	~HumanA(void);

	void	attack(void) const;

private:

	std::string	_name;
	Weapon		&_weapon;

};

#endif
