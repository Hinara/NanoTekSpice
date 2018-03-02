/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4011
*/

#ifndef COMP4011_HPP_
	#define COMP4011_HPP_
	#include "SuperComponent.hpp"

class Comp4011	:	public SuperComponent
{
public:
	Comp4011(const std::string &);
	~Comp4011() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
	using InputPair = std::pair<PinNumber, PinNumber>;
	using CorrespondanceMap = std::unordered_map<PinNumber, InputPair>;
	static const CorrespondanceMap	_valuesTab;
};

#endif /* !COMP4011_HPP_ */
