/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4094
*/

#ifndef COMP4094_HPP_
	#define COMP4094_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Comp4094	:	public SuperComponent
{
public:
	Comp4094(const std::string &);
	~Comp4094();
	nts::Tristate		internalCompute(PinNumber);
	static const PinMap	pins;
};

#endif /* !COMP4094_HPP_ */
