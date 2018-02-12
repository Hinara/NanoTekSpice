/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Nano
*/

#ifndef NANO_HPP_
	#define NANO_HPP_

#include <string>

struct	chipset_s {
	std::string	_comp;
	std::string	_name;
};

struct	link_s {
	std::string	_nameO;
	int		_pinO;
	std::string	_nameT;
	int		_pinT;
};

#endif /* !NANO_HPP_ */
