/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:24:12 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/03 20:19:48 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{

public:

	Brain(void);
	Brain(const Brain &src);
	~Brain(void);

	Brain	&operator = (const Brain &right);
	void	init_ideas(std::string one_idea);

protected:

	std::string	ideas[100];

private:

};

#endif
