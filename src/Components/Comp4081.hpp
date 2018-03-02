/*
** EPITECH PROJECT, 2018
** 4081
*/

#ifndef COMP4081_HPP_
	#define COMP4081_HPP_
	#include "SuperComponent.hpp"

class Comp4081	:	public SuperComponent
{
public:
	Comp4081(const std::string &);
	~Comp4081() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
	using InputPair = std::pair<PinNumber, PinNumber>;
	using CorrespondanceMap = std::unordered_map<PinNumber, InputPair>;
	static const CorrespondanceMap	_valuesTab;
};

#endif /* !COMP4081_HPP_ */
