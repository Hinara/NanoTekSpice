/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
** Basic Logic Gate
*/

#ifndef LOGICGATE_HPP_
	#define LOGICGATE_HPP_
	#include "IComponent.hpp"

class LogicGate {
public:
	~LogicGate() = delete;
	static nts::Tristate	andGate(nts::Tristate p1, nts::Tristate p2);
	static nts::Tristate	xorGate(nts::Tristate p1, nts::Tristate p2);
	static nts::Tristate	orGate(nts::Tristate p1, nts::Tristate p2);
	static nts::Tristate	notGate(nts::Tristate p1);
	static nts::Tristate	xnorGate(nts::Tristate p1, nts::Tristate p2);
	static nts::Tristate	nandGate(nts::Tristate p1, nts::Tristate p2);
	static nts::Tristate	norGate(nts::Tristate p1, nts::Tristate p2);
};

#endif /* !LOGICGATE_HPP_ */
