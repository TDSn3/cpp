/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastScalaire.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/09 16:08:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CastScalaire_HPP
# define CastScalaire_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdint>

class CastScalaire
{
public:

	CastScalaire(int arg);
	CastScalaire(float arg);
	CastScalaire(double arg);
	CastScalaire(char arg);
	CastScalaire(const CastScalaire &src);
	~CastScalaire(void);

	CastScalaire	&operator = (const CastScalaire &right);
					operator int(void);
					operator float(void);
					operator double(void);
					operator char(void);

protected:

private:

	int		_index[4]; 		// [0] int | [1] float | [2] double | [3] char
	int64_t	_stock_data;
};

#endif
