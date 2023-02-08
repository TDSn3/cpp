/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:48:16 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/08 16:19:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PresidentialPardonForm_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:

	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	~PresidentialPardonForm(void);

	PresidentialPardonForm	&operator = (const PresidentialPardonForm &right);
	std::string	get_target() const;
	void		action(void);

protected:

private:

	const std::string	_target;

};

#endif
