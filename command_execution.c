//
// Created by franciszek on 29.10.2020.
//

#include "constants.h"
#include "command_execution.h"
#include "text_manipulation.h"

void executeCommand(struct Command command, const char *inputString, char* outputString, char * clipboard) {
    switch (command.commandType) {
        case 0: {
            cut(inputString, outputString, clipboard, command.firstArgument, command.secondArgumentNumber);
        } break;
        case 1: {
            copy(inputString,  clipboard, command.firstArgument, command.secondArgumentNumber);
        } break;
        case 2: {
            paste(inputString, outputString, clipboard, command.firstArgument);
        } break;
    }
}

