/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4040
*/

#ifndef COMP4040_HPP_
	#define COMP4040_HPP_
	#include <map>
	#include "SuperComponent.hpp"

class Comp4040	:	public SuperComponent
{
public:
	Comp4040(const std::string &);
	~Comp4040();
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
	int				_value;
	nts::Tristate			_lastState;
	const std::map<PinNumber, int>	_valuesTab = {
		{9, 0},
		{7, 1},
		{6, 2},
		{5, 3},
		{3, 4},
		{2, 5},
		{4, 6},
		{13, 7},
		{12, 8},
		{14, 9},
		{15, 10},
		{1, 11}
	};
};

#endif /* !COMP4040_HPP_ */
