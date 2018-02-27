/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4017
*/

#ifndef COMP4017_HPP_
	#define COMP4017_HPP_
	#include <unordered_map>
	#include "LogicGates.hpp"
	#include "SuperComponent.hpp"

class Comp4017	:	public SuperComponent
{
public:
	Comp4017(const std::string &);
	~Comp4017() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	using CorrespondanceMap = std::unordered_map<PinNumber, int>;
	static const PinMap		_pins;
	int				_value;
	nts::Tristate			_lastState;
	static const CorrespondanceMap	_valuesTab;
};

#endif /* !COMP4017_HPP_ */
