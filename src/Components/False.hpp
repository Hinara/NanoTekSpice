/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** False
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_

#include <string>
#include "SuperComponent.hpp"

class False	:	public SuperComponent
{
public:
	False(const std::string &);
	~False();
	nts::Tristate		internalCompute(PinNumber);
	static const PinMap	pins;
};

#endif /* !FALSE_HPP_ */
