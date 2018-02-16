/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4069
*/

#ifndef COMP4069_HPP_
	#define COMP4069_HPP_
	#include "SuperComponent.hpp"

class Comp4069	:	public SuperComponent
{
public:
	Comp4069(const std::string &);
	~Comp4069();
	nts::Tristate		internalCompute(PinNumber) final;
	static const PinMap	pins;
};

#endif /* !COMP4069_HPP_ */
