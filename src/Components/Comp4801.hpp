/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4801
*/

#ifndef COMP4801_HPP_
	#define COMP4801_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Comp4801	:	public SuperComponent
{
public:
	Comp4801(const std::string &);
	~Comp4801();
	nts::Tristate	internalCompute(std::size_t);
	const std::string	getName() const { return _name; }
	static const std::unordered_map<size_t, PinStatus> pins;
private:
	const std::string	_name;
};

#endif /* !COMP4801_HPP_ */
