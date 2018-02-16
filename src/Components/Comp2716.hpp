/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 2716
*/

#ifndef COMP2716_HPP_
	#define COMP2716_HPP_
	#include "SuperComponent.hpp"

class Comp2716	:	public SuperComponent
{
public:
	Comp2716(const std::string &);
	~Comp2716();
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
};

#endif /* !COMP2716_HPP_ */
