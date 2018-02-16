/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** component factory
*/

#ifndef COMPONENTFACTORY_HPP_
	#define COMPONENTFACTORY_HPP_
	#include <memory>
	#include <functional>
	#include <map>
	#include "IComponent.hpp"

namespace nts
{
	class ComponentFactory {
	public:
		using CompPtr = std::unique_ptr<nts::IComponent>;
		using FnctPtr = std::function<CompPtr(const std::string &)>;
		using CreateCompMap = std::map<const std::string, FnctPtr>;
		ComponentFactory();
		~ComponentFactory();
		CompPtr	createComponent(const std::string &type,
			const std::string &value);
	private:
		template<class T>
		static CompPtr	createElem(
			const std::string &value)
			{
				return std::unique_ptr<T> (new T(value));
			}
		static const CreateCompMap	_map;
	};
}

#endif /* !COMPONENTFACTORY_HPP_ */
