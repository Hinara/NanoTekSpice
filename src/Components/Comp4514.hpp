/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4514
*/

#ifndef COMP4514_HPP_
	#define COMP4514_HPP_
	#include "SuperComponent.hpp"

class Comp4514	:	public SuperComponent
{
public:
	Comp4514(const std::string &);
	~Comp4514();
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
};

#endif /* !COMP4514_HPP_ */
