/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastScalaire.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/11 10:44:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTSCALAIRE_HPP
# define CASTSCALAIRE_HPP

# include <iostream>
# include <string>
# include <exception>

class CastScalaire
{
public:

	class InvalidString : public std::exception
	{
		void	print_error(void) const;
	};
	
	CastScalaire(char *arg);
	CastScalaire(const CastScalaire &src);
	~CastScalaire(void);

	CastScalaire	&operator = (const CastScalaire &right);

protected:

private:

	int			check_one_point_float(char *arg) const;
	int			if_int(char *arg);
	int			if_float(char *arg);
	int			if_double(char *arg);
	void		print_bits(void) const;

	int			_index[4];	// [0] int | [1] float | [2] double | [3] char
	__int64_t	_stock_data;
};

#endif
