/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/03 22:33:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

public:

	Animal(void);
	Animal(std::string type);
	Animal(const Animal &src);
	virtual	~Animal(void);

	Animal			&operator = (const Animal &right);
	std::string		getType(void) const;
	virtual void	makeSound(void) const = 0;

protected:

	std::string	_type;

private:

};

#endif
