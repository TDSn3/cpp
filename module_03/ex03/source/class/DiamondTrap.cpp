/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:38:35 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/06 16:03:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

/* ************************************************************************** */
/*                                                                            */
/*   Constructeur															  */
/*                                                                            */
/* ************************************************************************** */
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "\033[00;02;03m" << "DiamondTrap : Default constructor called" << "\033[00m" << std::endl;
	FragTrap	a("util");
	this->_hit_points = ClapTrap::_hit_points;
	this->_energy_points = ClapTrap::_energy_points;
	this->_attack_damage = a.get__attack_damage();
}

/*   COPY   ***************************************************************** */

DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap_src) : ClapTrap(DiamondTrap_src.get__name() + "_clap_name"), FragTrap(DiamondTrap_src.get__name()), ScavTrap(DiamondTrap_src.get__name()), _name(DiamondTrap_src.get__name())
{
	std::cout << "\033[32;02;03m" << "DiamondTrap : Copy constructor called" << "\033[00m" << std::endl;
	this->_hit_points = DiamondTrap_src.get__hit_points();
	this->_energy_points = DiamondTrap_src.get__energy_points();
	this->_attack_damage = DiamondTrap_src.get__attack_damage();
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

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap   : " << this->_name << std::endl;
	std::cout << "Hit points    : " << this->_hit_points << std::endl;
	std::cout << "Energy points : " << this->_energy_points << std::endl;
	std::cout << "Attack damage : " << this->_attack_damage << std::endl;

	std::cout << "\nClapTrap      : " << ClapTrap::_name << std::endl;
}

std::string	DiamondTrap::get__name(void) const
{
	return (this->_name);
}

/*   PRIVATE   ************************************************************** */

/* ************************************************************************** */
