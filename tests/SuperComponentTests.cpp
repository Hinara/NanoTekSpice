/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** SuperComponent tests
*/

#include "../src/Components/Output.hpp"
#include "../src/Components/Input.hpp"
#include "../src/Components/Comp4071.hpp"
#include "../src/Errors.hpp"
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

Test(misc, supercomponentloop)
{
	Input			i("None");
	Comp4071		orComp("None");
	Output			o("None");

	orComp.setLink(1, i, 1);
	orComp.setLink(2, orComp, 3);
	o.setLink(1, orComp, 3);
	i.setState(nts::FALSE);
	o.simulate();
	cr_assert(o.getValue() == nts::UNDEFINED);
	i.setState(nts::TRUE);
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
	i.setState(nts::FALSE);
	o.simulate();
	cr_assert(o.getValue() == nts::TRUE);
}

Test(misc, supercomponentdoublelink)
{
	Input			i("None");
	Output			o("None");

	o.setLink(1, i, 1);
	cr_assert_throw(o.setLink(1, i, 1), Err::LinkError);
}

Test(misc, supercomponentlinkunknown)
{
	Input			i("None");
	Output			o("None");

	cr_assert_throw(o.setLink(0, i, 1), Err::LinkError);
}

Test(misc, supercomponentgetinputnotlinked)
{
	Output			o("None");

	o.simulate();
	cr_assert(o.getValue() == nts::UNDEFINED);
}

Test(misc, supercomponentdump)
{
	Comp4071		c("None");

	c.dump();
}

Test(misc, supercomponentisinputlinked)
{
	Input			i("None");
	Output			o("None");

	cr_assert(o.isInputLinked(1) == nts::FALSE);
	o.setLink(1, i, 1);
	cr_assert(o.isInputLinked(1) == nts::TRUE);
}
