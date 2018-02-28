/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** LogicGates Xor Test
*/

#include "../src/Components/LogicGates.hpp"
#include <criterion/criterion.h>

Test(misc, xor_true_true)
{
	cr_assert(LogicGates::xorGate(nts::TRUE, nts::TRUE) == nts::FALSE);
}

Test(misc, xor_true_false)
{
	cr_assert(LogicGates::xorGate(nts::TRUE, nts::FALSE) == nts::TRUE);
}

Test(misc, xor_false_false)
{
	cr_assert(LogicGates::xorGate(nts::FALSE, nts::FALSE) == nts::FALSE);
}

Test(misc, xor_und_false)
{
	cr_assert(LogicGates::xorGate(nts::UNDEFINED, nts::FALSE) ==
		nts::UNDEFINED);
}