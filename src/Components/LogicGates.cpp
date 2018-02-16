#include "LogicGates.hpp"

nts::Tristate	SimpleElec::andGate(nts::Tristate p1, nts::Tristate p2)
{
	if (p1 == nts::FALSE || p2 == nts::FALSE)
		return (nts::FALSE);
	if (p1 == nts::TRUE && p2 == nts::TRUE)
		return (nts::TRUE);
	return (nts::UNDEFINED);
	
}

nts::Tristate	SimpleElec::xorGate(nts::Tristate p1, nts::Tristate p2)
{
	if (p1 == nts::UNDEFINED || p2 == nts::UNDEFINED)
		return (nts::UNDEFINED);
	if (p1 == p2)
		return (nts::FALSE);
	return (nts::TRUE);
}

nts::Tristate	SimpleElec::orGate(nts::Tristate p1, nts::Tristate p2)
{
	if (p1 == nts::TRUE || p2 == nts::TRUE)
		return (nts::TRUE);
	if (p1 == nts::FALSE && p2 == nts::FALSE)
		return (nts::FALSE);
	return (nts::UNDEFINED);
}

nts::Tristate	SimpleElec::notGate(nts::Tristate p1)
{
	if (p1 == nts::UNDEFINED)
		return (nts::UNDEFINED);
	if (p1 == nts::FALSE)
		return (nts::TRUE);
	return (nts::FALSE);
}

nts::Tristate	SimpleElec::xnorGate(nts::Tristate p1, nts::Tristate p2)
{
	return notGate(xorGate(p1, p2));
}

nts::Tristate	SimpleElec::nandGate(nts::Tristate p1, nts::Tristate p2)
{
	return notGate(andGate(p1, p2));
}

nts::Tristate	SimpleElec::norGate(nts::Tristate p1, nts::Tristate p2)
{
	return notGate(orGate(p1, p2));
}