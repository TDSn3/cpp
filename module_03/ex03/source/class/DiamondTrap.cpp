/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:38:35 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/31 19:56:02 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   Constructeur															  */
/*                                                                            */
/* ************************************************************************** */
DiamondTrap::DiamondTrap(std::string name) : _name(name) , ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "\033[00;02;03m" << "DiamondTrap : Default constructor called" << "\033[00m" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

/*   COPY   ***************************************************************** */

DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap_src)
{
	std::cout << "\033[32;02;03m" << "DiamondTrap : Copy constructor called" << "\033[00m" << std::endl;
	(void) DiamondTrap_src;
}

/* ************************************************************************** */
/*                                                                            */
/*   Destructeur															  */
/*                                                                            */
/* ************************************************************************** */
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "\033[31;01m" << "DiamondTrap : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   Opérateur																  */
/*                                                                            */
/* ************************************************************************** */

/*   INTERNE   *************************************************************** */

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &right)
{
	std::cout << "\033[33;02;03m" << "DiamondTrap : Copy assignment operator called" << "\033[00m" << std::endl;
	(void) right;
	return (*this);
}

/*   EXTERNE   ************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   PUBLIC   *************************************************************** */

void	DiamondTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0)
	{
		std::cout << "\033[33m"
		<< "DiamondTrap "
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
		<< "DiamondTrap "
		<< "\033[33;01m"
			<< this->_name
				<< "\033[00m\033[33m"
		<< " has no energy to attack."
		<< "\033[00m" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{

}

/*   PRIVATE   ************************************************************** */

/* ************************************************************************** */
