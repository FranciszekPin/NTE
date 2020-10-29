//
// Created by franciszek on 27.10.2020.
//

#ifndef NTE_COMMAND_INTERPRETATION_H
#define NTE_COMMAND_INTERPRETATION_H

#endif //NTE_COMMAND_INTERPRETATION_H

char* getCommand(int n, char * command_tape);
char* normalizeCommand(char * commandToNormalize);
struct Command interpretCommand(char * command);
