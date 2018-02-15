/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4013
*/

#ifndef COMP4013_HPP_
	#define COMP4013_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Comp4013	:	public SuperComponent
{
public:
	Comp4013(const std::string &);
	~Comp4013();
	nts::Tristate		internalCompute(PinNumber);
	static const PinMap	pins;
};

#endif /* !COMP4013_HPP_ */
