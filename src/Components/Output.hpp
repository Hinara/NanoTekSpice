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
	~Output();
	nts::Tristate		internalCompute(PinNumber) final;
	static const PinMap	pins;
	void simulate();
	nts::Tristate	getValue();
private:
	nts::Tristate		_state;
};

#endif /* !OUTPUT_HPP_ */
