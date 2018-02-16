/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4001
*/

#ifndef COMP4001_HPP_
	#define COMP4001_HPP_
	#include "SuperComponent.hpp"

class Comp4001	:	public SuperComponent
{
public:
	Comp4001(const std::string &);
	~Comp4001();
	nts::Tristate		internalCompute(PinNumber) final;
	static const PinMap	pins;
};

#endif /* !COMP4001_HPP_ */
