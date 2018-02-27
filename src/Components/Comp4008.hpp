/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4008
*/

#ifndef COMP4008_HPP_
	#define COMP4008_HPP_
	#include "SuperComponent.hpp"

class Comp4008	:	public SuperComponent
{
public:
	Comp4008(const std::string &);
	~Comp4008() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
	std::pair<nts::Tristate, nts::Tristate>	bitFullAdder(
		nts::Tristate, nts::Tristate, nts::Tristate);
};

#endif /* !COMP4008_HPP_ */