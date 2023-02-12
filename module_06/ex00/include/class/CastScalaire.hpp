/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastScalaire.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/12 12:57:28 by tda-silv         ###   ########.fr       */
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
		public:

		void	print_error(void) const;
	};
	
	CastScalaire(char *arg);
	CastScalaire(const CastScalaire &src);
	~CastScalaire(void);

	CastScalaire	&operator = (const CastScalaire &right);
					operator int(void);
					operator float(void);
					operator double(void);
					operator char(void);
	int				get_print_0(void) const;
	int				get_print_1(void) const;
	int				get_print_2(void) const;
	int				get_print_3(void) const;
	static void		print_arg(CastScalaire x);

protected:

private:

	int			check_one_point_float(char *arg) const;
	int			if_char(char *arg);
	int			if_int(char *arg);
	int			if_float(char *arg);
	int			if_double(char *arg);
	int			if_string(char *arg);
	void		print_bits(void) const;

	int			_index[4];	// [0] int | [1] float | [2] double | [3] char
	int			_print[4];	// [0] int | [1] float | [2] double | [3] char
	__int64_t	_stock_data;
	std::string	_stock_arg;
};

#endif
