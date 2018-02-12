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
		static std::unique_ptr<nts::IComponent>	create4001(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create4008(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create4011(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create4013(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create4017(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create4030(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create4040(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create4069(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create4071(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create4081(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create4094(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create4514(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create4801(const std::string &value);
		static std::unique_ptr<nts::IComponent>	create2716(const std::string &value);
		static std::unique_ptr<nts::IComponent>	createInput(const std::string &value);
		static std::unique_ptr<nts::IComponent>	createOutput(const std::string &value);
		static std::unique_ptr<nts::IComponent>	createClock(const std::string &value);
		static std::unique_ptr<nts::IComponent>	createFalse(const std::string &value);
		static std::unique_ptr<nts::IComponent>	createTrue(const std::string &value);
	private:
		std::map<const std::string, FnctPtr>	_map = {
			{"4001", create4001},
			{"4008", create4008},
			{"4011", create4011},
			{"4013", create4013},
			{"4017", create4017},
			{"4030", create4030},
			{"4040", create4040},
			{"4069", create4069},
			{"4071", create4071},
			{"4081", create4081},
			{"4094", create4094},
			{"4514", create4514},
			{"4801", create4801},
			{"2716", create2716},
			{"input", createInput},
			{"output", createOutput},
			{"clock", createClock},
			{"true", createTrue},
			{"false", createFalse}
		};
	};
}

#endif /* !COMPONENTFACTORY_HPP_ */
