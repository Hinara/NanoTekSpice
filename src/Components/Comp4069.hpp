/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4069
*/

#ifndef COMP4069_HPP_
	#define COMP4069_HPP_

#include <string>
#include <map>
#include <utility>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Comp4069	:	public SuperComponent
{
public:
	Comp4069(const std::string &);
	~Comp4069();
	nts::Tristate	internalCompute(std::size_t);
	const std::string	getName() const { return _name; }
	static std::unordered_map<size_t, PinStatus> getPin();
private:
	const std::string	_name;
};

#endif /* !COMP4069_HPP_ */
