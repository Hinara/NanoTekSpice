/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** SuperComponent
*/

#include <algorithm>
#include "../Errors.hpp"
#include "SuperComponent.hpp"

SuperComponent::SuperComponent(std::unordered_map<size_t, PinStatus> pins)
{
	std::for_each(pins.begin(), pins.end(),
		[this](std::pair<size_t, PinStatus> pin) {
			if (pin.second == Output)
				this->output.insert(std::make_pair(pin.first, std::make_pair(nts::UNDEFINED, false)));
			else
				this->input.insert(std::make_pair(pin.first, std::make_pair(nullptr, 0)));
		});
}

SuperComponent::~SuperComponent()
{
}


const std::unordered_map<std::size_t, std::pair<nts::IComponent *, std::size_t>>	SuperComponent::getInput() const
{
	return input;
}

nts::Tristate	SuperComponent::compute(std::size_t pin)
{
	auto &p = this->output.at(pin);
	if (p.second) {
		return (p.first);
	}
	p.second = true;
	nts::Tristate res = this->internalCompute(pin);
	p.second = false;
	return (res);
}

void		SuperComponent::setLink(std::size_t pin,
					nts::IComponent &other,
					std::size_t otherpin)
{
	try {
		auto &p = this->input.at(pin);
		if (p.first)
		throw Err::LinkError("Pin already linked");
		p.first = &other;
		p.second = otherpin;
	} catch (std::exception) {
		throw Err::LinkError("Unknown Pin");
	}
}

nts::Tristate	SuperComponent::getInputPin(std::size_t pin) const
{
	const auto &p = this->input.at(pin);
	return p.first->compute(p.second);//
}

void		SuperComponent::dump() const
{
	
}