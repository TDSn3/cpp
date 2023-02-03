/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/03 20:00:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Dog : public Animal
{

public:

	Dog(void);
	Dog(const Dog &src);
	~Dog(void);

	Dog				&operator = (const Dog &right);
	virtual void	makeSound(void) const;

protected:

private:

	Brain	*_own_brain;

};

#endif
