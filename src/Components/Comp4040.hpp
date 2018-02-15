/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4040
*/

#ifndef COMP4040_HPP_
	#define COMP4040_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Comp4040	:	public SuperComponent
{
public:
	Comp4040(const std::string &);
	~Comp4040();
	nts::Tristate		internalCompute(std::size_t);
	static const PinMap	pins;
};

#endif /* !COMP4040_HPP_ */
