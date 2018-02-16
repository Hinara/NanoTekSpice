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
	nts::Tristate		internalCompute(PinNumber) final;
	static const PinMap	pins;
};

#endif /* !TRUE_HPP_ */
