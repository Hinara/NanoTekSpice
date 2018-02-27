/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
** Command Line Interface Header
*/

#ifndef CLI_H_
	#define CLI_H_
	#include "Graph.hpp"

class Cli
{
public:
	Cli(Graph &g);
	Cli();
	~Cli();
	void	start();
private:
	Graph	&_g;
	void	input(const std::string &s, nts::Tristate state);
	void	simulateAndDisplay();
	void	simulate();
	void	loop();
	void	dump();
	void	display();
	void	executeCommand(const std::string &s);
};

#endif /* CLI_H_ */
