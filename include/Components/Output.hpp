/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_

#include <string>
#include "IComponent.hpp"

class Output	:	public nts::IComponent
{
	public:
		Output(const std::string &);
		~Output();
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

#endif /* !OUTPUT_HPP_ */
