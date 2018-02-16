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
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
};

#endif /* !COMP4801_HPP_ */
