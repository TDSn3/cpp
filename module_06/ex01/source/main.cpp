/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/12 15:01:12 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

//static void	wait_return(void);
static uintptr_t	serialize(Data* ptr);
static Data*		deserialize(uintptr_t raw);

int main(void)
{
	Data	new_data;
	Data	*stock;

	new_data.i = 42;
	stock = deserialize(serialize(&new_data));

	std::cout << "copy     : " << &new_data << " " << new_data.i << std::endl;
	std::cout << "original : " << stock << " " << stock->i << std::endl;

	return (0);
}

static uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

static Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

//static void	wait_return(void)
//{
//	std::cout << "\033[00;02;03m"
//	<< "Press any key to continue"
//	<< "\033[00m" << std::endl;
//	std::cin.get();
//}
