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

class True	:	public nts::IComponent
{
public:
	True(const std::string &);
	~True();
	nts::Tristate	compute(std::size_t pin = 1);
	void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
	void		dump() const;
	const std::string	getName() const { return _name; }
private:
	const std::string	_name;
};

#endif /* !TRUE_HPP_ */
