/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4081
*/

#ifndef COMP4081_HPP_
	#define COMP4081_HPP_
	#include "SuperComponent.hpp"

class Comp4081	:	public SuperComponent
{
public:
	Comp4081(const std::string &);
	~Comp4081();
	nts::Tristate		internalCompute(PinNumber) final;
	static const PinMap	pins;
};

#endif /* !COMP4081_HPP_ */
