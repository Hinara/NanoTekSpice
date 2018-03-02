/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4001
*/

#ifndef COMP4001_HPP_
	#define COMP4001_HPP_
	#include "SuperComponent.hpp"

class Comp4001	:	public SuperComponent
{
public:
	Comp4001(const std::string &);
	~Comp4001() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
	using InputPair = std::pair<PinNumber, PinNumber>;
	using CorrespondanceMap = std::unordered_map<PinNumber, InputPair>;
	static const CorrespondanceMap	_valuesTab;
};

#endif /* !COMP4001_HPP_ */
