/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** LogicGates Or Test
*/

#include "../src/Components/LogicGates.hpp"
#include <criterion/criterion.h>

Test(misc, or_true_true)
{
	cr_assert(LogicGates::orGate(nts::TRUE, nts::TRUE) == nts::TRUE);
}

Test(misc, or_true_und)
{
	cr_assert(LogicGates::orGate(nts::TRUE, nts::UNDEFINED) == nts::TRUE);
}

Test(misc, or_false_und)
{
	cr_assert(LogicGates::orGate(nts::FALSE, nts::UNDEFINED) ==
		nts::UNDEFINED);
}

Test(misc, or_false_false)
{
	cr_assert(LogicGates::orGate(nts::FALSE, nts::FALSE) == nts::FALSE);
}