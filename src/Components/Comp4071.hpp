/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4071
*/

#ifndef COMP4071_HPP_
	#define COMP4071_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Comp4071	:	public SuperComponent
{
public:
	Comp4071(const std::string &);
	~Comp4071();
	nts::Tristate	internalCompute(std::size_t);
	const std::string	getName() const { return _name; }
	static std::unordered_map<size_t, PinStatus> getPin();
private:
	const std::string	_name;
};

#endif /* !COMP4071_HPP_ */
