/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** 4094
*/

#ifndef COMP4094_HPP_
	#define COMP4094_HPP_
	#include "SuperComponent.hpp"

class Comp4094	:	public SuperComponent
{
public:
	Comp4094(const std::string &);
	~Comp4094() = default;
	virtual void	dump() const final override;
protected:
	nts::Tristate		internalCompute(PinNumber) final;
private:
	using CorrespondanceMap = std::unordered_map<PinNumber, int>;
	static const PinMap	_pins;
	int			_value;
	int			_display;
	nts::Tristate		_notQs;
	nts::Tristate		_lastState;
	static const CorrespondanceMap	_valuesTab;
};

#endif /* !COMP4094_HPP_ */
