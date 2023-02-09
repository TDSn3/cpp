/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArgError.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/09 12:32:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGERROR_HPP
# define ARGERROR_HPP

# include <iostream>
# include <string>
# include <exception>

class ArgError : public std::exception
{
public:

	ArgError(std::string _message_error);
	ArgError(const ArgError &src);
	~ArgError(void);

	const std::string	get_grade(void) const;

protected:

private:

	const std::string	_message_error;
};

#endif
