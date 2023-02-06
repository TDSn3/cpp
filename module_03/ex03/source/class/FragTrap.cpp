/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:35:04 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/06 15:36:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   Constructeur															  */
/*                                                                            */
/* ************************************************************************** */
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[00;02;03m" << "FragTrap : Default constructor called" << "\033[00m" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

/*   COPY   ***************************************************************** */

FragTrap::FragTrap(const FragTrap &FragTrap_src) : ClapTrap(FragTrap_src.get__name())
{
	std::cout << "\033[32;02;03m" << "FragTrap : Copy constructor called" << "\033[00m" << std::endl;
	this->_hit_points = FragTrap_src.get__hit_points();
	this->_energy_points = FragTrap_src.get__energy_points();
	this->_attack_damage = FragTrap_src.get__attack_damage();
}

/* ************************************************************************** */
/*                                                                            */
/*   Destructeur															  */
/*                                                                            */
/* ************************************************************************** */
FragTrap::~FragTrap(void)
{
	std::cout << "\033[31;01m" << "FragTrap : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   Opérateur																  */
/*                                                                            */
/* ************************************************************************** */

/*   INTERNE   *************************************************************** */

FragTrap	&FragTrap::operator=(const FragTrap &right)
{
	std::cout << "\033[33;02;03m" << "FragTrap : Copy assignment operator called" << "\033[00m" << std::endl;
	this->_hit_points = right.get__hit_points();
	this->_energy_points = right.get__energy_points();
	this->_attack_damage = right.get__attack_damage();
	return (*this);
}

/*   EXTERNE   ************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   PUBLIC   *************************************************************** */

void	FragTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0)
	{
		std::cout << "\033[33m"
		<< "FragTrap "
		<< "\033[33;01m"
			<< this->_name
				<< "\033[00m\033[33m"
		<< " attacks "
		<< "\033[33;01m"
			<< target
				<< "\033[00m\033[33m"
		<< ", causing " << this->_attack_damage << " points of damage!"
		<< "\033[00m" << std::endl;
		this->_energy_points--;
	}
	else
		std::cout << "\033[33m"
		<< "FragTrap "
		<< "\033[33;01m"
			<< this->_name
				<< "\033[00m\033[33m"
		<< " has no energy to attack."
		<< "\033[00m" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "\033[33m"
	<< "FragTrap "
	<< "\033[33;01m"
			<< this->_name
				<< "\033[00m\033[33m"
	<< " asks for high fives."
	<< "\033[00m" << std::endl;
}

/*   PRIVATE   ************************************************************** */

/* ************************************************************************** */
