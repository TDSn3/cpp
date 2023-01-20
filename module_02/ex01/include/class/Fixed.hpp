/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/20 18:54:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

public:

	Fixed(void);
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed &fixed_b);
	~Fixed(void);
	Fixed	&operator=(const Fixed &fixed_b);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:

	int			_nb;
	const int	_size_fract;	// 8

/* ************************************************************************** */
/*  	 					bits réservés par _size_fract					  */
/*  	 							  vvvvvvvv								  */
/*   int : -------- -------- -------- --------								  */
/* ************************************************************************** */

/* ************************************************************************** */
/*			  exposant														  */
/*			  vvvvvvv-v														  */
/*   float : -------- -------- -------- --------							  */
/*           seeeeeee emmmmmmm mmmmmmmm mmmmmmmm							  */
/*           01111111 10000000 00000000 00000000 = 0x7F800000				  */
/* ************************************************************************** */

};

#endif
