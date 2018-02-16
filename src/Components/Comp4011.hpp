/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4011
*/

#ifndef COMP4011_HPP_
	#define COMP4011_HPP_
	#include "SuperComponent.hpp"

class Comp4011	:	public SuperComponent
{
public:
	Comp4011(const std::string &);
	~Comp4011();
	nts::Tristate		internalCompute(PinNumber) final;
	static const PinMap	pins;
};

#endif /* !COMP4011_HPP_ */
