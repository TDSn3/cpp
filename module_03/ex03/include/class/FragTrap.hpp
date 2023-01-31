/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:26:06 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/31 20:23:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{

public:

	FragTrap(std::string name);
	FragTrap(const FragTrap &FragTrap_src);
	~FragTrap(void);

	FragTrap	&operator = (const FragTrap &right);

	void	attack(const std::string &target);
	void	highFivesGuys(void);

protected:

private:

};

#endif
