/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4094
*/

#ifndef COMP4094_HPP_
	#define COMP4094_HPP_
	#include "SuperComponent.hpp"

class Comp4094	:	public SuperComponent
{
public:
	Comp4094(const std::string &);
	~Comp4094() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
};

#endif /* !COMP4094_HPP_ */
