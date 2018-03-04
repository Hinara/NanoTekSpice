/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4801
*/

#ifndef COMP4801_HPP_
	#define COMP4801_HPP_
	#include "SuperComponent.hpp"

class Comp4801	:	public SuperComponent
{
public:
	Comp4801(const std::string &);
	~Comp4801() = default;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	using CorrespondanceMap = std::unordered_map<PinNumber, int>;
	static const CorrespondanceMap	_valuesTab;
	static const PinMap	_pins;
	uint16_t	getAddress() const;
	uint8_t		getValue() const;
	uint8_t		_values[1024];
};

#endif /* !COMP4801_HPP_ */
