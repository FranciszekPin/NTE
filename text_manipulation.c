//
// Created by franciszek on 28.10.2020.
//

#include "text_manipulation.h"

char * cut(const char *inputString, char* outputString, int position, int numberOfCharactersToCut) {
    int i=0;
    while (i != position) {
        outputString[i] = inputString[i];
        i++;
    }

    while (i < position + numberOfCharactersToCut) {
        i++;
    }

    while (inputString[i] != '\0') {
        outputString[i - numberOfCharactersToCut] = inputString[i];
        i++;
    }

    outputString[i - numberOfCharactersToCut] = '\0';

    return outputString;
}
