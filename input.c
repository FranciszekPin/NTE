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
;
}

void readCommandTape(char * command_tape)
{
    int c;
    int i=0;
    while((c = getchar()) != '\n') {
        command_tape[i] = c;
        i++;
    }

    return command_tape;
}