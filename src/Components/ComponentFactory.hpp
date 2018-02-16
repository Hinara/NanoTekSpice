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
		std::unique_ptr<nts::IComponent>	createComponent(
			const std::string &type, const std::string &value);
	private:
		template<class T>
		static std::unique_ptr<nts::IComponent>	createElem(
			const std::string &value)
			{
				return std::unique_ptr<T> (new T(value));
			}
		static const std::map<const std::string, FnctPtr>	_map;
	};
}

#endif /* !COMPONENTFACTORY_HPP_ */
