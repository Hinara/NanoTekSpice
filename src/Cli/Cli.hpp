/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
** Command Line Interface Header
*/

#ifndef CLI_H_
	#define CLI_H_
	#include "../Nano.hpp"

class Cli
{
public:
	Cli(graph_s &g);
	Cli();
	~Cli();
	void	start();
private:
	graph_s	&_g;
	void	input(const std::string &s, nts::Tristate state);
	void	simulate();
	void	loop();
	void	dump();
	void	display();
	void	executeCommand(const std::string &s);
};

#endif /* CLI_H_ */
