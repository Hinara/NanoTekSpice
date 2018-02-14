/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

#include "SuperComponent.hpp"

class Input	:	public SuperComponent
{
public:
	Input(const std::string &);
	~Input();
	nts::Tristate	internalCompute(std::size_t);
	const std::string	getName() const { return _name; }
	static const std::unordered_map<size_t,  PinStatus>	pins;
private:
	const std::string	_name;
};

#endif /* !INPUT_HPP_ */
