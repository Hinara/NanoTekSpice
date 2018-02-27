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
	~Comp4040() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
	int				_value;
	nts::Tristate			_lastState;
	const std::map<PinNumber, int>	_valuesTab = {
		{9, 1 << 0},
		{7, 1 << 1},
		{6, 1 << 2},
		{5, 1 << 3},
		{3, 1 << 4},
		{2, 1 << 5},
		{4, 1 << 6},
		{13, 1 << 7},
		{12, 1 << 8},
		{14, 1 << 9},
		{15, 1 << 10},
		{1, 1 << 11}
	};
};

#endif /* !COMP4040_HPP_ */
