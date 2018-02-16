/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4013
*/

#ifndef COMP4013_HPP_
	#define COMP4013_HPP_
	#include "SuperComponent.hpp"

class Comp4013	:	public SuperComponent
{
public:
	Comp4013(const std::string &);
	~Comp4013();
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
};

#endif /* !COMP4013_HPP_ */
