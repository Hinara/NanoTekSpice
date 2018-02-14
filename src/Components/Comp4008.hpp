/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4008
*/

#ifndef COMP4008_HPP_
	#define COMP4008_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Comp4008	:	public SuperComponent
{
public:
	Comp4008(const std::string &);
	~Comp4008();
	nts::Tristate	internalCompute(std::size_t);
	const std::string	getName() const { return _name; }
	static const std::unordered_map<size_t, PinStatus> pins;
private:
	const std::string	_name;
};

#endif /* !COMP4008_HPP_ */
