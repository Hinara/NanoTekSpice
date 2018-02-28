/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** LogicGates Xnor Test
*/

#include "../src/Components/LogicGates.hpp"
#include <criterion/criterion.h>

Test(misc, xnor_true_true)
{
	cr_assert(LogicGates::xnorGate(nts::TRUE, nts::TRUE) == nts::TRUE);
}

Test(misc, xnor_true_false)
{
	cr_assert(LogicGates::xnorGate(nts::TRUE, nts::FALSE) == nts::FALSE);
}

Test(misc, xnor_false_false)
{
	cr_assert(LogicGates::xnorGate(nts::FALSE, nts::FALSE) == nts::TRUE);
}

Test(misc, xnor_und_false)
{
	cr_assert(LogicGates::xnorGate(nts::UNDEFINED, nts::FALSE) ==
		nts::UNDEFINED);
}