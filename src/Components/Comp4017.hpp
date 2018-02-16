/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4017
*/

#ifndef COMP4017_HPP_
	#define COMP4017_HPP_
	#include "SuperComponent.hpp"

class Comp4017	:	public SuperComponent
{
public:
	Comp4017(const std::string &);
	~Comp4017();
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
};

#endif /* !COMP4017_HPP_ */
