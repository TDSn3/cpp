/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/01/26 09:02:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>
# include <iostream>
# include <string>

/* ************************************************************************** */
/*                                                                            */
/*   Constructeur															  */
/*                                                                            */
/* ************************************************************************** */
ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "\033[00;02;03m" << "ClapTrap : default constructor called" << "\033[00m" << std::endl;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

/*   COPY   ***************************************************************** */

ClapTrap::ClapTrap(const ClapTrap &ClapTrap_src) : _name(ClapTrap_src.get__name())
{
	std::cout << "\033[32;02;03m" << "ClapTrap : Copy constructor called" << "\033[00m" << std::endl;
	this->_hit_points = ClapTrap_src.get__hit_points();
	this->_energy_points = ClapTrap_src.get__energy_points();
	this->_attack_damage = ClapTrap_src.get__attack_damage();
}

/* ************************************************************************** */
/*                                                                            */
/*   Destructeur															  */
/*                                                                            */
/* ************************************************************************** */
ClapTrap::~ClapTrap(void)
{
	std::cout << "\033[31;01m" << "ClapTrap : Destructor called" << "\033[00m" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   Opérateur																  */
/*                                                                            */
/* ************************************************************************** */

/*   INTERNE   *************************************************************** */

ClapTrap	&ClapTrap::operator=(const ClapTrap &right)
{
	std::cout << "\033[33;02;03m" << "ClapTrap : Copy assignment operator called" << "\033[00m" << std::endl;
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

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0)
	{
		std::cout << "\033[33m"
		<< "ClapTrap "
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
		<< "ClapTrap "
		<< "\033[33;01m"
			<< this->_name
				<< "\033[00m\033[33m"
		<< " has no energy to attack."
		<< "\033[00m" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "\033[33;02m"
	<< "ClapTrap "
	<< "\033[33;01m"
		<< this->_name
			<< "\033[00m\033[33;02m"
	<< " take " << amount << " damages!" 
	<< "\033[00m" << std::endl;
	this->_hit_points -= amount;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0)
	{
		std::cout << "\033[34m"
		<< "ClapTrap "
		<< "\033[34;01m"
			<< this->_name
				<< "\033[00m\033[34m"
		<< " regains " << amount << " hit points."
		<< "\033[00m" << std::endl;
		this->_energy_points--;
		this->_hit_points += amount;
	}
	else
		std::cout << "\033[33m"
		<< "ClapTrap "
		<< "\033[34;01m"
			<< this->_name
				<< "\033[00m\033[34m"
		<< " has no energy to repaire."
		<< "\033[00m" << std::endl;
}

const std::string	ClapTrap::get__name(void) const
{
	return (this->_name);
}

int	ClapTrap::get__hit_points(void) const
{
	return (this->_hit_points);
}

int	ClapTrap::get__energy_points(void) const
{
	return (this->_energy_points);
}

int	ClapTrap::get__attack_damage(void) const
{
	return (this->_attack_damage);
}

/* static */ void	ClapTrap::fight(ClapTrap &attacker, ClapTrap &victim, int amount)
{
	if (attacker.get__energy_points() > 0)
	{
		attacker.attack(victim.get__name());
		victim.takeDamage(amount);
	}
	else
		attacker.attack(victim.get__name());
}

/*   PRIVATE   ************************************************************** */

/* ************************************************************************** */
