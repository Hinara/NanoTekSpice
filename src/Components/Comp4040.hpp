/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4040
*/

#ifndef COMP4040_HPP_
	#define COMP4040_HPP_
	#include "SuperComponent.hpp"

class Comp4040	:	public SuperComponent
{
public:
	Comp4040(const std::string &);
	~Comp4040();
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
};

#endif /* !COMP4040_HPP_ */
