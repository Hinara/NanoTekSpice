/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4514
*/

#ifndef COMP4514_HPP_
	#define COMP4514_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Comp4514	:	public SuperComponent
{
public:
	Comp4514(const std::string &);
	~Comp4514();
	nts::Tristate	internalCompute(std::size_t) final;
	const std::string	getName() const { return _name; }
	static const std::unordered_map<size_t, PinStatus> pins;
private:
	const std::string	_name;
};

#endif /* !COMP4514_HPP_ */
