/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:09:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/08 18:13:43 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_CPP
# define INTERN_CPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Intern : public Form
{
public:

	Intern(std::string target);
	Intern(const Intern &src);
	~Intern(void);

	Intern	&operator = (const Intern &right);
	Form	*makeForm(std::string form_name, std::string form_target);

protected:

private:

};

#endif
