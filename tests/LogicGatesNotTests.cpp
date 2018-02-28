/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** LogicGates Not Test
*/

#include "../src/Components/LogicGates.hpp"
#include <criterion/criterion.h>

Test(misc, not_true)
{
	cr_assert(LogicGates::notGate(nts::TRUE) == nts::FALSE);
}

Test(misc, not_und)
{
	cr_assert(LogicGates::notGate(nts::UNDEFINED) == nts::UNDEFINED);
}

Test(misc, not_false)
{
	cr_assert(LogicGates::notGate(nts::FALSE) == nts::TRUE);
}
