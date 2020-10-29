//
// Created by franciszek on 28.10.2020.
//

#ifndef NTE_TEXT_MANIPULATION_H
#define NTE_TEXT_MANIPULATION_H

#endif //NTE_TEXT_MANIPULATION_H

void cut(const char *inputString, char* outputString, char * clipboard, int position, int numberOfCharactersToCut);

void copy(const char *inputString, char * clipboard, int position, int numberOfCharactersToCopy);

void paste(const char *inputString, char *outputString, const char * clipboard, int position);

void insert(const char *inputString, char *outputString, const char * text, int position);

