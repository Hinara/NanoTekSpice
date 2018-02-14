/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_

#include <utility>
#include <string>
#include "IComponent.hpp"
#include "SuperComponent.hpp"

class Output	:	public SuperComponent
{
public:
	Output(const std::string &);
	~Output();
	nts::Tristate	internalCompute(std::size_t);
	const std::string	getName() const { return _name; }
	static const std::unordered_map<size_t,  PinStatus>	pins;
private:
	const std::string	_name;
};

#endif /* !OUTPUT_HPP_ */
