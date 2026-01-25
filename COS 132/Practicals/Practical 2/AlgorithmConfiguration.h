#ifndef ALGORITHM_CONFIGURATION_H
#define ALGORITHM_CONFIGURATION_H

#include <iostream>

/// @brief This variable indicates the position in the structure the algorithm will start at.
extern int START;
/// @brief This variable indicates the position in the structure the algorithm will terminate at. In other words, when the algorithm reaches this position it will terminate.
extern int END;
/// @brief This variable indicates if the algorithm will move from forward i to i+1 in the structure, or backward i to i-1 in the structure.
extern bool MOVETONEXT;

/// @brief This is a special variable that is only used in certain function(s)
extern float AVERAGE;
/// @brief This is a special variable that is only used in certain function(s)
extern float VALUE;

/// @brief This function should print out the START variable.
void printStart();
/// @brief This function should print out the END variable.
void printEnd();
/// @brief This function should print out the MOVETONEXT variable.
void printMoveToNext();
/// @brief This function should print out the AVERAGE variable.
void printAverage();
/// @brief This function should print out the VALUE variable.
void printValue();

#endif // ALGORITHM_CONFIGURATION_H