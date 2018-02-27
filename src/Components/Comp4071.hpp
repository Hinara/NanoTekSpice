/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4071
*/

#ifndef COMP4071_HPP_
	#define COMP4071_HPP_
	#include "SuperComponent.hpp"

class Comp4071	:	public SuperComponent
{
public:
	Comp4071(const std::string &);
	~Comp4071() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
};

#endif /* !COMP4071_HPP_ */
