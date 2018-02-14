/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** True
*/

#ifndef TRUE_HPP_
	#define TRUE_HPP_

#include <string>
#include <memory>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class True	:	public SuperComponent
{
public:
	True(const std::string &);
	~True();
	nts::Tristate	internalCompute(std::size_t);
	const std::string	getName() const { return _name; }
	static const std::unordered_map<size_t,  PinStatus>	pins;
private:
	const std::string	_name;
};

#endif /* !TRUE_HPP_ */
