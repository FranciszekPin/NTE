#include<stdio.h>
#include "constants.h"
#include "input.h"
#include "command_interpretation.h"
#include "text_manipulation.h"

int main() {
    static char input_tape[N];
    static char command_tape[N];

    readInputTape(input_tape);
    readCommandTape(command_tape);


    int cursor = 0;
    while (command_tape[cursor] != '\0') {
        while (command_tape[cursor] != '$' && command_tape[cursor] != '\0')
            cursor++;
        if (command_tape[cursor] != '\0') {
            cursor++;
            struct Command command = interpretCommand(getCommand(cursor, command_tape));
            printf("%d %d %d %s\n", command.commandType, command.firstArgument, command.secondArgumentNumber, command.secondArgumentText);
        }


    }

    return 0;
}
