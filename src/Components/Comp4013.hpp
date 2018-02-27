/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4013
*/

#ifndef COMP4013_HPP_
	#define COMP4013_HPP_
	#include <utility>
	#include "LogicGates.hpp"
	#include "SuperComponent.hpp"

class Comp4013	:	public SuperComponent
{
public:
	Comp4013(const std::string &);
	~Comp4013() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	nts::Tristate		_value[2] = { nts::FALSE, nts::FALSE };
	nts::Tristate		_lastState[2] = { nts::TRUE, nts::TRUE };
	static const PinMap	_pins;
};

#endif /* !COMP4013_HPP_ */
