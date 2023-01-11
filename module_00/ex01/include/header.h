/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:12:11 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/11 13:58:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <iostream>
# include <iomanip>
# include <list>
# include <stdio.h>
# include <stdlib.h>

# include "./class/Contact.hpp"
# include "./class/PhoneBook.hpp"

int	compare_menu(std::string str, PhoneBook *instance_phone_book);

#endif
