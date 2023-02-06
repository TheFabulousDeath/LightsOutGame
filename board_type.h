#ifndef BOARD_TYPE_H
#define BOARD_TYPE_H
#include <stdlib.h>
#include <stdio.h>

typedef struct board 
{
    int width;
    int height;
    int * boardArray;
} * board_type;

int readByIndex(board_type board, int i, int j)
{
    return board->boardArray[board->height* i + j];
}

void writeByIndex(board_type board, int i, int j, int value)
{
    board->boardArray[board->height * i + j] = value;
}

board_type initializeBoard (int height, int width)
{
    board_type board = (board_type)calloc(1, sizeof(board_type));
    height += 2;
    width += 2;
    board->boardArray = (int*) malloc(sizeof(int)*height*width);
    board->height = height;
    board->width = width;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++)
        {
            writeByIndex(board, i , j, 1);
        }
    }
    writeByIndex(board, height/2, width/2, 0);
    return board;
}

void printBoard (board_type board, FILE * stream)
{
    if (stream == NULL) stream = stdout;
    if(board == NULL) return;
    for(int i = 1; i < board->height - 1; i++)
    {
        for(int j = 1; j < board->width - 1; j++)
        {
            fprintf(stream, "%d ", readByIndex(board, i, j));
        }
        fprintf(stream, "\n");
    }
    fprintf(stream, "\n");
    for(int i = 0; i < board->width;i++) fprintf(stream, "-");
    fprintf(stream, "\n");
}

void makeMove(board_type board, int i, int j)
{
    writeByIndex(board, i-1, j, readByIndex(board, i-1, j) > 0 ? 0 : 1);
    for(int k = j-1; k <= j+1; k++)
    {
        writeByIndex(board, i, k, readByIndex(board, i, k) > 0 ? 0 : 1);
    }
    writeByIndex(board, i+1, j, readByIndex(board, i+1, j) > 0 ? 0 : 1);
}
#endif