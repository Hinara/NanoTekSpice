/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_
	#include "IComponent.hpp"
	#include <unordered_map>

class SuperComponent : public nts::IComponent
{
public:
	nts::Tristate	compute(std::size_t pin = 1) override;
	void		setLink(std::size_t, nts::IComponent &, std::size_t) override;
	void		dump() const override;
	const std::unordered_map<std::size_t, std::pair<nts::IComponent *, std::size_t>>	getInput() const;
protected:
	enum PinStatus {
		Input,
		Output
	};
	SuperComponent(std::unordered_map<size_t, PinStatus>);
	nts::Tristate	getInputPin(std::size_t) const;
	virtual ~SuperComponent();
	virtual nts::Tristate	internalCompute(std::size_t) = 0;
private:
	std::unordered_map<std::size_t, std::pair<nts::IComponent *, std::size_t>> input;
	std::unordered_map<std::size_t, std::pair<nts::Tristate, bool>>	output;
};

#endif /* OUTPUT_HPP_ */