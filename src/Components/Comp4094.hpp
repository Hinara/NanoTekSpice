/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4094
*/

#ifndef COMP4094_HPP_
	#define COMP4094_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Comp4094	:	public SuperComponent
{
public:
	Comp4094(const std::string &);
	~Comp4094();
	nts::Tristate	internalCompute(std::size_t);
	const std::string	getName() const { return _name; }
	static std::unordered_map<size_t, PinStatus> getPin();
private:
	const std::string	_name;
};

#endif /* !COMP4094_HPP_ */
