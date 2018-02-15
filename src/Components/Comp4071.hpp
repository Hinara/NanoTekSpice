/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4071
*/

#ifndef COMP4071_HPP_
	#define COMP4071_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Comp4071	:	public SuperComponent
{
public:
	Comp4071(const std::string &);
	~Comp4071();
	nts::Tristate		internalCompute(PinNumber);
	static const PinMap	pins;
};

#endif /* !COMP4071_HPP_ */
