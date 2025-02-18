#ifndef CACHEIFYOUCAN_H
#define CACHEIFYOUCAN_H

#include <stdio.h>
#include <stdlib.h>

// Structure that saves lenght and price 
typedef struct {
    int length;
    int price;
} Piece_price;

// Function calculates the maximum profit from cutting the rod
void cutting_Rod(int rodLength, Piece_price pieces[], int size_of_pieces);

#endif // CACHEIFYOUCAN_H