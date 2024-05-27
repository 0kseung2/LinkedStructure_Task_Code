//
//  CheckMatching.h
//  Lab03
//
//  Created by Jeman Park on 2024/03/26.
//



#ifndef MAZEEXPLORER_H
#define MAZEEXPLORER_H

#include "StackType.h"
using namespace std;

#define MAZE_SIZE 6


void printLocation(location point);
bool mazeExplorer(char map[][MAZE_SIZE], location entryPoint, location exitPoint);

#endif /* CHECKMATCHING_H */
