//
// Created by franciszek on 27.10.2020.
//

#ifndef NTE_CONSTANTS_H
#define NTE_CONSTANTS_H

#endif //NTE_CONSTANTS_H

#define N 20000

struct command
{
    int commandType;    //{0:cut 1:copy 2:paste 3:insert}
    int firstArgument;
    int secondArgumentNumber; //if it is cut or copy
    char * secondArgumentText;        //if it is insert
};