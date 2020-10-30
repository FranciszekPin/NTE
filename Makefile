main: main.c command_execution.c input.c command_interpretation.c text_manipulation.c
	gcc command_execution.c input.c command_interpretation.c text_manipulation.c main.c -o main -xc -Wall -Wextra -Werror -lm
