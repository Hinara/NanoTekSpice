/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Output
*/

#ifndef SUPERCOMPONENT_HPP_
	#define SUPERCOMPONENT_HPP_
	#include "IComponent.hpp"
	#include <unordered_map>

class SuperComponent : public nts::IComponent
{
public:
	using PinNumber = std::size_t;
	nts::Tristate	compute(PinNumber pin = 1) override;
	void	setLink(PinNumber, nts::IComponent &, PinNumber) override;
	void	dump() const override;
	bool	isInput(PinNumber pin) const;
	bool	inputIsLink(PinNumber) const;
	bool	outputIsLink(PinNumber) const;
protected:
	enum PinStatus {
		INPUT,
		OUTPUT
	};
	using PinMap = std::unordered_map<PinNumber, PinStatus>;
	SuperComponent(const PinMap &);
	nts::Tristate	getInputPin(PinNumber) const;
	virtual ~SuperComponent();
	virtual nts::Tristate	internalCompute(PinNumber) = 0;
private:
	using Lock = bool;
	using PinInput = std::pair<nts::IComponent *, PinNumber>;
	using PinOutput = std::pair<nts::Tristate, Lock>;
	std::unordered_map<PinNumber, PinInput> 	input;
	std::unordered_map<PinNumber, PinOutput>	output;
};

#endif /* SUPERCOMPONENT_HPP_ */