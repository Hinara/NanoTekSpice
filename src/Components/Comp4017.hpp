/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4017
*/

#ifndef COMP4017_HPP_
	#define COMP4017_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Comp4017	:	public SuperComponent
{
public:
	Comp4017(const std::string &);
	~Comp4017();
	nts::Tristate	internalCompute(PinNumber);
	static const PinMap	pins;
};

#endif /* !COMP4017_HPP_ */
