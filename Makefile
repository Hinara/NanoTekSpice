##
## EPITECH PROJECT, 2017
## Nanotekspice
## File description:
## Makefile
##

CXX	=	g++ #--coverage

RM	=	rm -rf

CXXFLAGS	+=	-Wall -Wextra

NAME		=	nanotekspice

NAME_COVER	=	$(NAME).cover

SRCS		=						\
			src/Parser.cpp				\
			src/Errors.cpp				\
			src/Cli.cpp				\
			src/Graph.cpp				\
			src/Kernel.cpp				\
			src/ArgumentsParser.cpp			\
			src/Components/ComponentFactory.cpp	\
			src/Components/SuperComponent.cpp	\
			src/Components/True.cpp			\
			src/Components/False.cpp		\
			src/Components/Clock.cpp		\
			src/Components/Input.cpp		\
			src/Components/Output.cpp		\
			src/Components/Comp2716.cpp		\
			src/Components/Comp4001.cpp		\
			src/Components/Comp4008.cpp		\
			src/Components/Comp4011.cpp		\
			src/Components/Comp4013.cpp		\
			src/Components/Comp4017.cpp		\
			src/Components/Comp4030.cpp		\
			src/Components/Comp4040.cpp		\
			src/Components/Comp4069.cpp		\
			src/Components/Comp4071.cpp		\
			src/Components/Comp4081.cpp		\
			src/Components/Comp4094.cpp		\
			src/Components/Comp4514.cpp		\
			src/Components/Comp4801.cpp		\
			src/Components/LogicGates.cpp		\

SRCS_MAIN	=	src/Main.cpp				\

SRCS_TESTS	=	\
			tests/FalseTest.cpp		\
			tests/TrueTest.cpp		\
			tests/InputTest.cpp		\
			tests/ClockTest.cpp		\
			tests/OutputTest.cpp		\
			tests/ComponentFactoryTest.cpp	\
			tests/LogicGatesAndTests.cpp	\
			tests/LogicGatesOrTests.cpp	\
			tests/LogicGatesXorTests.cpp	\
			tests/LogicGatesNotTests.cpp	\
			tests/LogicGatesNandTests.cpp	\
			tests/LogicGatesNorTests.cpp	\
			tests/LogicGatesXnorTests.cpp	\
			tests/SuperComponentTests.cpp	\
			tests/Comp4001Tests.cpp		\
			tests/Comp4008Tests.cpp		\
			tests/Comp4011Tests.cpp		\
			tests/Comp4030Tests.cpp		\
			tests/Comp4040Tests.cpp		\
			tests/Comp4069Tests.cpp		\
			tests/Comp4071Tests.cpp		\
			tests/Comp4081Tests.cpp		\
			tests/Comp4017Tests.cpp		\

OBJS		=	$(SRCS:.cpp=.o)

OBJS_MAIN	=	$(SRCS_MAIN:.cpp=.o)

OBJS_TESTS	=	$(SRCS_TESTS:.cpp=.o)

COVER_FILE	=	nanotekspice.info

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_MAIN)
	$(CXX) $(OBJS) $(OBJS_MAIN) -o $(NAME) $(LDFLAGS)

$(NAME_COVER): CXXFLAGS += --coverage
$(NAME_COVER): LDFLAGS += --coverage
$(NAME_COVER): $(OBJS) $(OBJS_TESTS)
	$(CXX) $(OBJS) $(OBJS_TESTS) -o $(NAME_COVER) -lcriterion $(LDFLAGS)

cover:	$(NAME_COVER)
	lcov --base-directory . --directory . --zerocounters -q
	./$(NAME_COVER)
	lcov --base-directory . --directory . -c -o $(COVER_FILE)
	lcov --remove $(COVER_FILE) "/usr*" -o $(COVER_FILE) # remove output for external libraries
	rm -rf ../test_coverage
	genhtml -o ../test_coverage -t "$(NAME) test coverage" --num-spaces 4 $(COVER_FILE)

tests_run: fclean $(NAME_COVER)
	./$(NAME_COVER)

test:	$(NAME)
	./test_nano/testing_script.sh ./$(NAME) ./test_nano/units_tests

clean:
	$(RM) $(OBJS) $(OBJS_MAIN) $(OBJS_TESTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test cover tests_run test
