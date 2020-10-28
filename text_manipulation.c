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

    copy(inputString, clipboard, position, numberOfCharactersToCut);

    i=position+numberOfCharactersToCut;
    while (inputString[i] != '\0') {
        outputString[i - numberOfCharactersToCut] = inputString[i];
        i++;
    }

    outputString[i - numberOfCharactersToCut] = '\0';
}

void copy(const char *inputString, char * clipboard, int position, int numberOfCharactersToCopy) {
    int i=position;
    while (i < position+numberOfCharactersToCopy) {
        clipboard[i-position] = inputString[i];
        i++;
    }
    clipboard[i - position] = '\0';
}