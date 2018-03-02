/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4030
*/

#ifndef COMP4030_HPP_
	#define COMP4030_HPP_
	#include "SuperComponent.hpp"

class Comp4030	:	public SuperComponent
{
public:
	Comp4030(const std::string &);
	~Comp4030() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
	using InputPair = std::pair<PinNumber, PinNumber>;
	using CorrespondanceMap = std::unordered_map<PinNumber, InputPair>;
	static const CorrespondanceMap	_valuesTab;
};

#endif /* !COMP4030_HPP_ */
