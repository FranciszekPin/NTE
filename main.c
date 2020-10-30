#include<stdio.h>
#include <memory.h>
#include "constants.h"
#include "input.h"
#include "command_interpretation.h"
#include "text_manipulation.h"
#include "command_execution.h"

int main() {
    static char input_tape[N];
    static char command_tape[N];
    static char result_tape[N];
    static char clipboard[N];

    clipboard[0] = '\0';

    strcpy(result_tape, command_tape);

    readInputTape(input_tape);
    readCommandTape(command_tape);


    int cursor = 0;
    while (command_tape[cursor] != '\0') {
        while (command_tape[cursor] != '$' && command_tape[cursor] != '\0')
            cursor++;
        if (command_tape[cursor] != '\0') {
            cursor++;
            struct Command command = interpretCommand(getCommand(cursor, command_tape));
            executeCommand(command, input_tape, result_tape, clipboard);
            strcpy(input_tape, result_tape);
        }


    }

    printf("%s\n", result_tape);

    return 0;
}
