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
#include "IComponent.hpp"

class Input	:	public nts::IComponent
{
	public:
		Input(const std::string &);
		~Input();
		nts::Tristate	compute(std::size_t pin = 1);
		void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
		void		dump() const;
		const std::string	getName() const { return _name; }
		const nts::Tristate	getValue() const { return _value; }
		void			setValue(nts::Tristate val) { _value = val; }
	private:
		const std::string	_name;
		nts::Tristate		_value;
};

#endif /* !INPUT_HPP_ */
