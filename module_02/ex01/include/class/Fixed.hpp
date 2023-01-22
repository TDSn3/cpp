/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/22 11:25:36 by tda-silv         ###   ########.fr       */
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
	const int	_size_fract;				// = 8

/* ************************************************************************** */
/*  	 					bits réservés par _size_fract					  */
/*  	 							  vvvvvvvv								  */
/*   int : -------- -------- -------- --------								  */
/* ************************************************************************** */

/* ************************************************************************** */
/*   s : signe																  */
/*   e : exposant															  */
/*   m : mantisse															  */
/*                                                                            */
/*			  exposant														  */
/*			  vvvvvvv-v														  */
/*   float : -------- -------- -------- --------							  */
/*           seeeeeee emmmmmmm mmmmmmmm mmmmmmmm							  */
/*           01111111 10000000 00000000 00000000 = 0x7F800000 (infinity)	  */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Exposant:																  */
/*           sEEEEEEE Emmmmmmm mmmmmmmm mmmmmmmm							  */
/*           -0000000 0------- -------- -------- = 2^-126					  */
/*           -0000000 1------- -------- -------- = 2^-126 (1 - 127 = 126)	  */
/*           -0000001 1------- -------- -------- = 2^-124 (2 - 127 = 124)	  */
/*           -0000011 1------- -------- -------- = 2^-120 (7 - 127 = 120)	  */
/*											 ... = ...						  */
/*           -1111111 1------- -------- -------- = 2^128  (255 - 127 = 128)	  */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Mantisse:																  */
/*           seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM							  */
/*           -------- -0000000 00000000 00000000 = 0						  */
/*           -------- -1000000 00000000 00000000 = 0.5						  */
/*           -------- -0100000 00000000 00000000 = 0.25						  */
/*           -------- -0010000 00000000 00000000 = 0.125					  */
/*           -------- -0001000 00000000 00000000 = 0.0625					  */
/*           -------- -0000100 00000000 00000000 = 0.03125					  */
/*           -------- -0000010 00000000 00000000 = 0.015625					  */
/*           -------- -0000001 00000000 00000000 = 0.0078125				  */
/*											 ... = ...						                     */
/*           -------- -1101001 00000000 00000000 = 0.5 + 0.25 + 0.0625 + 0.0078125 = 0.8203125   */
/*											 ... = ...						                     */
/*           -------- -1111111 11111111 11111111 = 0.9999998807907104		  */
/* ************************************************************************** */

/* ************************************************************************** */
/*   float = s * (e * m)													  */
/*   99.25 = 1 * (2^6 * 1.55078125)											  */
/*                                                                            */
/*			 seeeeeee emmmmmmm mmmmmmmm mmmmmmmm							  */
/*   99.25 = 01000010 11000110 10000000 00000000							  */
/*                                                                            */
/*   s = 1                                                                    */
/*   e = 2^6 (133 - 127 = 6)												  */
/*   m = 1 (invisibe) + 0.5 + 0.03125 + 0.015625 + 0.00390625 = 1.55078125    */
/* ************************************************************************** */

/* ************************************************************************** */
/*   4294967296.0 :															  */
/*           seeeeeee emmmmmmm mmmmmmmm mmmmmmmm							  */
/*			 01001111 10000000 00000000 00000000							  */
/*																			  */
/*   s    -e--   m															  */
/*   1 * (2^32 * 1) = 4294967296											  */
/*																			  */
/*   99.333 :																  */
/*           seeeeeee emmmmmmm mmmmmmmm mmmmmmmm							  */
/*			 01000010 11000110 10101010 01111111							  */
/*																			  */
/*   s    -e-   --------m--------											  */
/*   1 * (2^6 * 1.552078127861023) = 99.333									  */
/* ************************************************************************** */

};

#endif
