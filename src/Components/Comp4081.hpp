/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4081
*/

#ifndef COMP4081_HPP_
	#define COMP4081_HPP_

#include <string>
#include <unordered_map>
#include <utility>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Comp4081	:	public SuperComponent
{
public:
	Comp4081(const std::string &);
	~Comp4081();
	nts::Tristate	internalCompute(std::size_t);
	const std::string	getName() const { return _name; }
	static const std::unordered_map<size_t,  PinStatus>	pins;
private:
	const std::string	_name;
};

#endif /* !COMP4081_HPP_ */
