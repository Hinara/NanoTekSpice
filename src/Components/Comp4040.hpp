/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4040
*/

#ifndef COMP4040_HPP_
	#define COMP4040_HPP_
	#include <unordered_map>
	#include "SuperComponent.hpp"

class Comp4040	:	public SuperComponent
{
public:
	Comp4040(const std::string &);
	~Comp4040() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	using CorrespondanceMap = std::unordered_map<PinNumber, int>;
	static const PinMap		_pins;
	int				_value;
	nts::Tristate			_lastState;
	static const CorrespondanceMap	_valuesTab;
};

#endif /* !COMP4040_HPP_ */
