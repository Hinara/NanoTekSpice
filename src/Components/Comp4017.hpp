/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4017
*/

#ifndef COMP4017_HPP_
	#define COMP4017_HPP_
	#include <map>
	#include "LogicGates.hpp"
	#include "SuperComponent.hpp"

class Comp4017	:	public SuperComponent
{
public:
	Comp4017(const std::string &);
	~Comp4017();
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap		_pins;
	int				_value;
	nts::Tristate			_lastState;
	const std::map<PinNumber, int>	_valuesTab = {
		{3, 0},
		{2, 1},
		{4, 2},
		{7, 3},
		{10, 4},
		{1, 5},
		{5, 6},
		{6, 7},
		{9, 8},
		{11, 9}
	};
};

#endif /* !COMP4017_HPP_ */
