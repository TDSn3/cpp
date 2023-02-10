/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastScalaire.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/10 20:26:18 by tda-silv         ###   ########.fr       */
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

};

#endif
