/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Nano
*/

#ifndef NANO_HPP_
	#define NANO_HPP_

#include <deque>
#include <string>
#include "Components/IComponent.hpp"

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

struct	graph_s {
	std::map<const std::string, std::unique_ptr<nts::IComponent>>	_graph;
	std::deque<std::string>	_output;
	std::deque<std::string>	_input;
	std::deque<std::string>	_clock;
};

#endif /* !NANO_HPP_ */
