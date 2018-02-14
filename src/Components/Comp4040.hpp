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
	nts::Tristate	internalCompute(std::size_t);
	const std::string	getName() const { return _name; }
	static std::unordered_map<size_t, PinStatus> getPin();
private:
	const std::string	_name;
};

#endif /* !COMP4040_HPP_ */
