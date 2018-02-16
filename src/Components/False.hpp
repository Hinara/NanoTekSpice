/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** False
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_
	#include "SuperComponent.hpp"

class False	:	public SuperComponent
{
public:
	False(const std::string &);
	~False();
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
};

#endif /* !FALSE_HPP_ */
