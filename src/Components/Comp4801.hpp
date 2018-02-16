/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4801
*/

#ifndef COMP4801_HPP_
	#define COMP4801_HPP_
	#include "SuperComponent.hpp"

class Comp4801	:	public SuperComponent
{
public:
	Comp4801(const std::string &);
	~Comp4801();
	nts::Tristate		internalCompute(PinNumber) final;
	static const PinMap	pins;
};

#endif /* !COMP4801_HPP_ */
