//
// Created by franciszek on 27.10.2020.
//

#include "command_interpretation.h"
#include "constants.h"

char* getCommand(int n, char * command_tape)
// returns first command starting from index n in command_tape
{
    int i=n;
    static char result[N];
    while(command_tape[i] != '$' && command_tape[i] != '\0') {
        result[i-n] = command_tape[i];
        i++;
    }
    result[i] = '\0';

    return result;
}