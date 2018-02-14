/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

#include <utility>
#include <string>
#include <exception>
#include "IComponent.hpp"

class Input	:	public nts::IComponent
{
public:
	Input(const std::string &);
	~Input();
	nts::Tristate	compute(std::size_t pin = 1);
	void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
	void		dump() const;
	const std::string	getName() const noexcept { return _name; }
	void		setValue(nts::Tristate val) noexcept { _value = val; }
private:
	const std::string	_name;
	nts::Tristate		_value;
};

#endif /* !INPUT_HPP_ */
