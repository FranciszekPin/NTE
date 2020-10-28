#include<stdio.h>
#include "constants.h"
#include "input.h"
#include "text_manipulation.h"



int main() {
    static char input_tape[N];
    static char command_tape[N];

    readInputTape(input_tape);
    readCommandTape(command_tape);

    return 0;
}
