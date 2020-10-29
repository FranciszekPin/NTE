//
// Created by franciszek on 27.10.2020.
//

#include <stdio.h>
#include "input.h"
#include "constants.h"

void readInputTape(char * input_tape)
{
    int c;
    int i=0;
    while((c = getchar()) != '\n') {
        input_tape[i] = c;
        i++;
    }
    input_tape[i] = '\0';
}

void readCommandTape(char * command_tape)
{
    int c;
    int i=0;
    while((c = getchar()) != '\n' && c != EOF) {
        command_tape[i] = c;
        i++;
    }

    command_tape[i] = '\0';

}