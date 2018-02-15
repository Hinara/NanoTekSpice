##
## EPITECH PROJECT, 2017
## Nanotekspice
## File description:
## Makefile
##

CXX	=	g++

RM	=	rm -rf

CXXFLAGS	+=	-Wall -Wextra

NAME		=	nanotekspice

SRCS		=							\
			src/Main.cpp					\
			src/Parser.cpp					\
			src/Errors.cpp					\
			src/Cli.cpp					\
			src/Graph.cpp					\
			src/Components/ComponentFactory.cpp		\
			src/Components/SuperComponent.cpp		\
			src/Components/True.cpp				\
			src/Components/False.cpp			\
			src/Components/Clock.cpp			\
			src/Components/Input.cpp			\
			src/Components/Output.cpp			\
			src/Components/Comp2716.cpp			\
			src/Components/Comp4001.cpp			\
			src/Components/Comp4008.cpp			\
			src/Components/Comp4011.cpp			\
			src/Components/Comp4013.cpp			\
			src/Components/Comp4017.cpp			\
			src/Components/Comp4030.cpp			\
			src/Components/Comp4040.cpp			\
			src/Components/Comp4069.cpp			\
			src/Components/Comp4071.cpp			\
			src/Components/Comp4081.cpp			\
			src/Components/Comp4094.cpp			\
			src/Components/Comp4514.cpp			\
			src/Components/Comp4801.cpp			\
			src/Components/SimpleElec.cpp			\


OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
