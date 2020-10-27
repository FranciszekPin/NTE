//
// Created by franciszek on 27.10.2020.
//

#include <stdbool.h>
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

bool endOfString(char * string, int index)
{
    return string[index] == '\0';
}

void removeSpaceFromTheEndOfStringIfOccurs(char *string, int index) {
    if (string[index - 1] == ' ')
        string[index - 1] = '\0';
    else
        string[index] = '\0';
}

char* normalizeCommand(char * commandToNormalize)
// transforms command into form: COMMAND firstArgument secondArgument, for example "COPY 3 5"
{
    static char normalizedCommand[N];
    int indexOfNormalizedCommand = 0;
    int indexOfCommandToNormalize = 0;
    bool lastCharWasSpace = false;

    while (!endOfString(commandToNormalize, indexOfCommandToNormalize)) {
        char actCharOfCommandToNormalize = commandToNormalize[indexOfCommandToNormalize];

        if ((actCharOfCommandToNormalize == ' ' && !lastCharWasSpace) || actCharOfCommandToNormalize != ' ') {
            lastCharWasSpace = (actCharOfCommandToNormalize == ' ') ? true : false;
            normalizedCommand[indexOfNormalizedCommand] = actCharOfCommandToNormalize;
            indexOfNormalizedCommand++;
        }

        indexOfCommandToNormalize++;
    }

    removeSpaceFromTheEndOfStringIfOccurs(normalizedCommand, indexOfNormalizedCommand);

    return normalizedCommand;

}