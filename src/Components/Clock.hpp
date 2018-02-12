/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** clock
*/

#ifndef CLOCK_HPP_
	#define CLOCK_HPP_

#include <string>
#include "IComponent.hpp"

class Clock	:	public nts::IComponent
{
public:
	Clock(const std::string &);
	~Clock();
	nts::Tristate	compute(std::size_t pin = 1);
	void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
	void		dump() const;
	const std::string	getName() const { return _name; }
private:
	const std::string	_name;
	nts::Tristate		_value;
};

#endif /* !CLOCK_HPP_ */
