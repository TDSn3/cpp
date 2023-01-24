/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/24 15:48:15 by tda-silv         ###   ########.fr       */
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

	Fixed				&operator = (const Fixed &fixed_b);
	Fixed				&operator + (const Fixed &right);
	Fixed				&operator - (const Fixed &right);
	Fixed				&operator * (const Fixed &right);
	Fixed				&operator / (const Fixed &right);
	Fixed				&operator ++();				// préfix  // ++x
	Fixed				operator ++(int useless);	// postfix // x++
	Fixed				&operator --();				// préfix  // --x
	Fixed				operator --(int useless);	// postfix // x--
		
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	int					toInt(void) const;
	float				toFloat(void) const;
	static Fixed			&min(Fixed &x, Fixed &y);
	static const Fixed	&min(const Fixed &x, const Fixed &y);
	static Fixed			&max(Fixed &x, Fixed &y);
	static const Fixed	&max(const Fixed &x, const Fixed &y);
	
private:
	
	int					_nb;
	const int			_size_fract;	// = 8

};

std::ostream			&operator<<(std::ostream &ofs, const Fixed &x);
int						operator > (const Fixed &left, const Fixed &right);
int						operator < (const Fixed &left, const Fixed &right);
int						operator >= (const Fixed &left, const Fixed &right);
int						operator <= (const Fixed &left, const Fixed &right);
int						operator == (const Fixed &left, const Fixed &right);
int						operator != (const Fixed &left, const Fixed &right);

#endif
