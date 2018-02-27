/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_
	#include "SuperComponent.hpp"

class Output	:	public SuperComponent
{
public:
	Output(const std::string &);
	~Output() = default;
	void simulate();
	nts::Tristate		getValue();
protected:
	nts::Tristate		internalCompute(PinNumber) final;
	nts::Tristate		_state;
private:
	static const PinMap	_pins;
};

#endif /* !OUTPUT_HPP_ */
