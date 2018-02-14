/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** clock
*/

#ifndef CLOCK_HPP_
	#define CLOCK_HPP_

#include <string>
#include "SuperComponent.hpp"

class Clock	:	public SuperComponent
{
public:
	Clock(const std::string &);
	~Clock();
	nts::Tristate	internalCompute(std::size_t);
	const std::string	getName() const { return _name; }
	static const std::unordered_map<size_t,  PinStatus>	pins;
private:
	const std::string	_name;
};

#endif /* !CLOCK_HPP_ */
