/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
** Basic Logic Gate
*/

#ifndef LOGICGATES_HPP_
	#define LOGICGATES_HPP_
	#include "IComponent.hpp"

class LogicGates {
public:
	~LogicGates() = delete;
	static nts::Tristate	andGate(nts::Tristate p1, nts::Tristate p2);
	static nts::Tristate	xorGate(nts::Tristate p1, nts::Tristate p2);
	static nts::Tristate	orGate(nts::Tristate p1, nts::Tristate p2);
	static nts::Tristate	notGate(nts::Tristate p1);
	static nts::Tristate	xnorGate(nts::Tristate p1, nts::Tristate p2);
	static nts::Tristate	nandGate(nts::Tristate p1, nts::Tristate p2);
	static nts::Tristate	norGate(nts::Tristate p1, nts::Tristate p2);
};

#endif /* !LOGICGATES_HPP_ */
