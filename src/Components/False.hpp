/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** False
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_

#include <string>
#include "SuperComponent.hpp"

class False	:	public SuperComponent
{
public:
	False(const std::string &);
	~False();
	nts::Tristate	internalCompute(std::size_t);
	const std::string	getName() const { return _name; }
	static const std::unordered_map<size_t,  PinStatus>	pins;
private:
	const std::string	_name;
};

#endif /* !FALSE_HPP_ */
