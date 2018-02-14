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
#include <exception>
#include <map>
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
private:
	const std::string	_name;
	std::pair<nts::IComponent *, std::size_t>	_links;
};

#endif /* !OUTPUT_HPP_ */
