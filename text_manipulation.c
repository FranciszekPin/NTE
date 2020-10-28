//
// Created by franciszek on 28.10.2020.
//

#include "text_manipulation.h"

void cut(const char *inputString, char* outputString, char * clipboard, int position, int numberOfCharactersToCut) {
    int i=0;
    while (i != position) {
        outputString[i] = inputString[i];
        i++;
    }

    while (i < position + numberOfCharactersToCut) {
        clipboard[i-position] = inputString[i];
        i++;
    }

    clipboard[i-position] = '\0';

    while (inputString[i] != '\0') {
        outputString[i - numberOfCharactersToCut] = inputString[i];
        i++;
    }

    outputString[i - numberOfCharactersToCut] = '\0';
}

