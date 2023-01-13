/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:50:38 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/13 11:27:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main(void)
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string		*stringPTR = &brain;
	std::string		&stringREF = brain;

	std::cout << "String adress            : " << &brain << std::endl;
	std::cout << "Adress stored in pointer : " << stringPTR << std::endl;
	std::cout << "Reference adress         : " << &stringREF << std::endl;

	std::cout << "\n";

	std::cout << "String content    : " << brain << std::endl;
	std::cout << "Pointer content   : " << *stringPTR << std::endl;
	std::cout << "Reference content : " << stringREF << std::endl;
	return (0);
}
