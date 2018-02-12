/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** False
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_

#include <string>
#include <memory>
#include "IComponent.hpp"

class False	:	public nts::IComponent
{
public:
	False(const std::string &);
	~False();
	nts::Tristate	compute(std::size_t pin = 1);
	void		setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin);
	void		dump() const;
	const std::string	getName() const { return _name; }
private:
	const std::string	_name;
};

#endif /* !FALSE_HPP_ */
