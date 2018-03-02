/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4069
*/

#ifndef COMP4069_HPP_
	#define COMP4069_HPP_
	#include "SuperComponent.hpp"

class Comp4069	:	public SuperComponent
{
public:
	Comp4069(const std::string &);
	~Comp4069() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	static const PinMap	_pins;
	using CorrespondanceMap = std::unordered_map<PinNumber, PinNumber>;
	static const CorrespondanceMap	_valuesTab;
};

#endif /* !COMP4069_HPP_ */
