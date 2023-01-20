/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/20 09:48:48 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{

public:

	Harl(void);
	~Harl(void);

	void	complain(int level);

private:

	typedef void	(Harl::*t_ptr_member)(void);
	t_ptr_member	tab_ptr_member[4];
	
/* ************************************************************************** */
/*  void			(Harl::*tab_ptr_member[4])(void);						  */
/* ************************************************************************** */

	void			debug(void);
	void			info(void);
	void			warning(void);
	void			error(void);

};

#endif
