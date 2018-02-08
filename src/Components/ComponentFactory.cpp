/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Componentfactory
*/

#include "ComponentFactory.hpp"

nts::ComponentFactory::ComponentFactory()
{
}

nts::ComponentFactory::~ComponentFactory()
{
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::createComponent(const std::string &type, const std::string &value)
{
	for (auto it = _map.begin(); it != _map.end(); it++) {
		if (type == it->first)
			return (it->second)(value);
	}
	return (_map.end()->second)(value);
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4001(const std::string &value)
{
	return std::unique_ptr<Comp4001> (new Comp4001(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4008(const std::string &value)
{
	return std::unique_ptr<Comp4008> (new Comp4008(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4011(const std::string &value)
{
	return std::unique_ptr<Comp4011> (new Comp4011(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4013(const std::string &value)
{
	return std::unique_ptr<Comp4013> (new Comp4013(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4017(const std::string &value)
{
	return std::unique_ptr<Comp4017> (new Comp4017(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4030(const std::string &value)
{
	return std::unique_ptr<Comp4030> (new Comp4030(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4040(const std::string &value)
{
	return std::unique_ptr<Comp4040> (new Comp4040(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4069(const std::string &value)
{
	return std::unique_ptr<Comp4069> (new Comp4069(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4071(const std::string &value)
{
	return std::unique_ptr<Comp4071> (new Comp4071(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4081(const std::string &value)
{
	return std::unique_ptr<Comp4081> (new Comp4081(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4094(const std::string &value)
{
	return std::unique_ptr<Comp4094> (new Comp4094(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4514(const std::string &value)
{
	return std::unique_ptr<Comp4514> (new Comp4514(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create4801(const std::string &value)
{
	return std::unique_ptr<Comp4801> (new Comp4801(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::create2716(const std::string &value)
{
	return std::unique_ptr<Comp2716> (new Comp2716(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::createInput(const std::string &value)
{
	return std::unique_ptr<Input> (new Input(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::createOutput(const std::string &value)
{
	return std::unique_ptr<Output> (new Output(value));
}

std::unique_ptr<nts::IComponent>	nts::ComponentFactory::createClock(const std::string &value)
{
	return std::unique_ptr<Clock> (new Clock(value));
}