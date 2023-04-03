#include "board_type.h"

int incrementFunction(int a)
{
    return a++;
}

void incrementFunctionByPointer(int* p)
{
    //p +=1; //memory unsafe operation
    *p +=1;
}

int main ()
{
    board_type gameBoard = initializeBoard(5,5);
    printBoard(gameBoard, NULL);
    makeMove(gameBoard, 2,2);
    printBoard(gameBoard, NULL);

    int theNumber = 5;
    theNumber = incrementFunction(theNumber);

    int * pointerToTheNumber = &theNumber;    
}