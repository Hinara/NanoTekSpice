/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** True
*/

#ifndef TRUE_HPP_
	#define TRUE_HPP_
	#include "SuperComponent.hpp"

class True	:	public SuperComponent
{
public:
	True(const std::string &);
	~True();
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
};

#endif /* !TRUE_HPP_ */
