/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** SuperComponent tests
*/

#include "../src/Components/Output.hpp"
#include "../src/Components/Input.hpp"
#include "../src/Components/LogicGates.hpp"
#include <criterion/criterion.h>

Test(misc, supercomponentisinputfalse)
{
	Input			i("None");

	cr_assert(i.isInput(1) == false);
}

Test(misc, supercomponentisinputtrue)
{
	Output			o("None");

	cr_assert(o.isInput(1));
}

Test(misc, supercomponentisoutputtrue)
{
	Input			i("None");

	cr_assert(i.isOutput(1));
}

Test(misc, supercomponentisoutputfalse)
{
	Output			o("None");

	cr_assert(o.isOutput(1) == false);
}
