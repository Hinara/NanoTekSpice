/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** component factory
*/

#ifndef COMPONENTFACTORY_HPP_
	#define COMPONENTFACTORY_HPP_
	#include <memory>
	#include <string>
	#include <functional>
	#include <map>
	#include "Comp2716.hpp"
	#include "Comp4001.hpp"
	#include "Comp4008.hpp"
	#include "Comp4011.hpp"
	#include "Comp4013.hpp"
	#include "Comp4017.hpp"
	#include "Comp4030.hpp"
	#include "Comp4040.hpp"
	#include "Comp4069.hpp"
	#include "Comp4071.hpp"
	#include "Comp4081.hpp"
	#include "Comp4094.hpp"
	#include "Comp4514.hpp"
	#include "Comp4801.hpp"
	#include "Input.hpp"
	#include "Output.hpp"
	#include "Clock.hpp"
	#include "True.hpp"
	#include "False.hpp"
	#include "IComponent.hpp"

using FnctPtr = std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>;

namespace nts
{
	class ComponentFactory {
	public:
		ComponentFactory();
		~ComponentFactory();
		std::unique_ptr<nts::IComponent>	createComponent(const std::string &type, const std::string &value);
	private:
		template<class T>
		static std::unique_ptr<nts::IComponent>	create_elem(const std::string &value)
			{
				return std::unique_ptr<T> (new T(value));
			}
		std::map<const std::string, FnctPtr>	_map = {
			{ "4001", create_elem<Comp4001> },
			{ "4008", create_elem<Comp4008> },
			{ "4011", create_elem<Comp4011> },
			{ "4013", create_elem<Comp4013> },
			{ "4017", create_elem<Comp4017> },
			{ "4030", create_elem<Comp4030> },
			{ "4040", create_elem<Comp4040> },
			{ "4069", create_elem<Comp4069> },
			{ "4071", create_elem<Comp4071> },
			{ "4081", create_elem<Comp4081> },
			{ "4094", create_elem<Comp4094> },
			{ "4514", create_elem<Comp4514> },
			{ "4801", create_elem<Comp4801> },
			{ "2716", create_elem<Comp2716> },
			{ "input", create_elem<Input> },
			{ "output", create_elem<Output> },
			{ "clock", create_elem<Clock> },
			{ "true", create_elem<True> },
			{ "false", create_elem<False> }
		};
	};
}

#endif /* !COMPONENTFACTORY_HPP_ */
