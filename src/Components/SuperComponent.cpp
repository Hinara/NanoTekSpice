/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** SuperComponent
*/

#include <algorithm>
#include "../Errors.hpp"
#include "SuperComponent.hpp"

SuperComponent::SuperComponent(const PinMap &pins)
{
	for (auto pin : pins) {
		if (pin.second & OUTPUT) {
			this->output.insert(std::make_pair(pin.first,
				std::make_pair(nts::UNDEFINED, false)));
		}
		if (pin.second & INPUT) {
			this->input.insert(std::make_pair(pin.first,
				std::make_pair(nullptr, 0)));
		}
	}
}

bool SuperComponent::isInput(PinNumber pin) const
{
	return (input.find(pin) != input.cend());
}

bool SuperComponent::isOutput(PinNumber pin) const
{
	return (output.find(pin) != output.cend());
}


nts::Tristate SuperComponent::compute(PinNumber pin)
{
	auto &p = this->output.at(pin);
	if (p.second)
		return (p.first);
	p.second = true;
	p.first = this->internalCompute(pin);
	p.second = false;
	return (p.first);
}

void SuperComponent::setLink(PinNumber pin,
			     nts::IComponent &other,
			     PinNumber otherpin)
{
	try {
		auto &p = this->input.at(pin);
		if (p.first)
			throw Err::LinkError("Pin already linked");
		p.first = &other;
		p.second = otherpin;
	} catch (Err::LinkError &e) {
		throw e;
	} catch (std::exception) {
		throw Err::LinkError("Unknown Pin");
	}
}

nts::Tristate SuperComponent::getInputPin(PinNumber pin) const
{
	const auto &p = this->input.at(pin);
	if (p.first == nullptr)
		return (nts::Tristate::UNDEFINED);
	return (p.first->compute(p.second));
}

void SuperComponent::dump() const
{
}

bool SuperComponent::isInputLinked(PinNumber pin) const
{
	return (input.at(pin).first != nullptr);
}