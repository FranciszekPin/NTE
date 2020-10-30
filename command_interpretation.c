//
// Created by franciszek on 27.10.2020.
//

#include <stdbool.h>
#include "command_interpretation.h"
#include "constants.h"

char* getCommand(int n, char * command_tape)
{
    int i=n;
    static char result[N];
    bool isLetter = true;
    while(command_tape[i] != '$' && command_tape[i] != '\0') {
        if ((command_tape[i] < 'A' || command_tape[i] > 'Z') && isLetter) {
            isLetter = false;
            result[i-n] = ' ';
            n--;
        }
        result[i-n] = command_tape[i];
        i++;
    }
    result[i-n] = '\0';

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

int getCommandType(char * command)
{
    int commandType = -1;

    if (command[0] == 'C' && command[1] == 'U')
        commandType = 0;
    else if (command[0] == 'C' && command[1] == 'O')
        commandType = 1;
    else if (command[0] == 'P' && command[1] == 'A')
        commandType = 2;
    else if (command[0] == 'I' && command[1] == 'N')
        commandType = 3;

    return commandType;
}

char * getFirstArgumentInCString(char * firstArgument, char * command)
{
    int i=0;
    while (command[i] != ' ')
        i++;

    i++;

    int index = 0;
    while (command[i] != ' ' && command[i] != '\0')
    {
        firstArgument[index] = command[i];
        i++;
        index++;
    }
    firstArgument[index] = '\0';

    return firstArgument;
}

char * getSecondArgumentInCString(char * secondArgument, char * command) {
    int i=0;
    while (command[i] != ' ')
        i++;

    i++;

    while (command[i] != ' ' && command[i] != '\0')
        i++;

    i++;


    int index = 0;
    while (command[i] != '\0')
    {
        secondArgument[index] = command[i];
        i++;
        index++;
    }
    secondArgument[index] = '\0';

    return secondArgument;
}

int getIntFromString(char * string) {
    int result = 0;
    int i=0;
    if (string[0] == '\0')
        return -1;
    while (string[i] != '\0') {
        if (string[i] < '0' || string[i] > '9')
            return -1;
        result = result * 10 + string[i] - '0';
        i++;
    }

    return result;
}

void getTextFromArgument(char * resultText, char * inputText) {
    int i=1;
    while (inputText[i] != '\"' && inputText[i] != '\0') {
        resultText[i-1] = inputText[i];
        i++;
    }
    resultText[i-1] = '\0';
}

struct Command interpretCommand(char * command)
{
    command = normalizeCommand(command);
    int commandType = getCommandType(command);

    char firstArgument[10];
    char secondArgument[N];
    char secondArgumentInText[N];
    getFirstArgumentInCString(firstArgument, command);
    getSecondArgumentInCString(secondArgument, command);

    int firstArgumentInInt = getIntFromString(firstArgument);
    int secondArgumentInInt = getIntFromString(secondArgument);
    if (secondArgumentInInt == -1)
        getTextFromArgument(secondArgumentInText, secondArgument);

    struct Command result;
    result.commandType = commandType;
    result.firstArgument = firstArgumentInInt;
    result.secondArgumentNumber = secondArgumentInInt;
    result.secondArgumentText = secondArgumentInText;

    return result;

}