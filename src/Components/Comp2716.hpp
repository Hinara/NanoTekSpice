/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 2716
*/

#ifndef COMP2716_HPP_
	#define COMP2716_HPP_

#include <string>
#include <map>
#include <utility>
#include "SuperComponent.hpp"

class Comp2716	:	public SuperComponent
{
public:
	Comp2716(const std::string &);
	~Comp2716();
	nts::Tristate		internalCompute(PinNumber);
	static const PinMap	pins;
};

#endif /* !COMP2716_HPP_ */
