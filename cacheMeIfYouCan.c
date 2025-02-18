#include <stdio.h>
#include <stdlib.h>
#include "cacheMeIfYouCan.h"

void cutting_Rod(int rodLength, Piece_price pieces[], int size_of_pieces) {
    int max_profit[rodLength + 1]; //stores best profit for each cut 
    int cuts[rodLength + 1]; //stores the lenght of the cut used

    for (int i = 0; i <= rodLength; i++) {
        max_profit[i] = 0;
        cuts[i] = 0;
    }

    //Loop thrpught all the possibilities and stored on max_profit the best best price
    for (int i = 1; i <= rodLength; i++) {
        max_profit[i] = 0;
        for (int j = 0; j < size_of_pieces; j++) {
            if (pieces[j].length <= i) {
                int newValue = pieces[j].price + max_profit[i - pieces[j].length];
                // checks if newValue is higher than the one stored before 
                if (newValue > max_profit[i]) {
                    max_profit[i] = newValue;
                    cuts[i] = pieces[j].length;
                }
            }
        }
    }

    //count how many times did we use the same type of lenght for a cut 
    int count[rodLength + 1];  
    for (int i = 0; i <= rodLength; i++) count[i] = 0;

    int length = rodLength;
    while (length > 0) {
        int cutLength = cuts[length];
        if (cutLength == 0) break;
        count[cutLength]++;
        length -= cutLength;
    }

    //Print cutting list
    printf("\nCutting list:\n");
    for (int i = 1; i <= rodLength; i++) {
        if (count[i] > 0) {
            int price = 0;
            for (int j = 0; j < size_of_pieces; j++) {
                if (pieces[j].length == i) {
                    price = pieces[j].price;
                    break;
                }
            }
            printf("%d @ %d = %d\n", count[i], i, count[i] * price);
        }
    }

    // Print the maximum profit
    printf("\nValue: %d\n", max_profit[rodLength]);

    // Print remaining if theres any
    if (length > 0) {
        printf("\nRemaining rod length: %d\n", length);
    }
}

int main() {
    //Takes user input of the rod 
    int rodLength;
    printf("Enter the supplied rod length: ");
    scanf("%d", &rodLength);

     //If rod length is 0 just return message
    if (rodLength == 0) {
        printf("You must enter a number higher than 0\n");
        return 0;
    } 

    Piece_price pieces[100]; 
    int size_of_pieces = 0;

    printf("Enter piece lengths and prices in the format <length, price>. Enter EOF (Ctrl+D) to stop inputting pieces.\n");

    while (scanf("%d, %d", &pieces[size_of_pieces].length, &pieces[size_of_pieces].price) == 2) {
        size_of_pieces++;
    }

    //checks if at least one input was made for length and price 
    if (size_of_pieces == 0) {
        printf("You must enter at least one piece length and price.\n");
        return 0;
    }

    cutting_Rod(rodLength, pieces, size_of_pieces);

    return 0;
}
