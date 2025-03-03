#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>

#include "piece_values.h"
#include "cut_list.h"
#include "vec.h"

void usage();

int main() {
    int rod_length = 0;

    // Make user to enter the rod length
    printf("Enter the supplied rod length: ");
    if (scanf("%d", &rod_length) != 1 || rod_length < 1) {
        usage();
    }

    // Create a vector to store piece prices
    Vec value_list = new_vec(sizeof(PieceLengthValue));

    printf("Enter piece lengths and prices in the format '<length>, <value>'. Enter EOF (Ctrl+D) to stop.\n");

    while (1) {
        PieceLengthValue item;
        
        // Read input until EOF
        if (scanf("%d, %d", &item.length, &item.value) != 2) {
            break;  // Exit loop on invalid input or EOF
        }

        if (item.length < 1 || item.value < 1) {
            fprintf(stderr, "Invalid input: length and value must be positive integers.\n");
            continue;
        }

        vec_add(value_list, &item);
    }

    // Ensure at least one piece was entered
    if (vec_length(value_list) == 0) {
        fprintf(stderr, "Error: You must enter at least one valid piece length and value.\n");
        return 1;
    }

    // print_piece_values(value_list);

    CutList *cl = optimal_cutlist_for(value_list, rod_length);

    cutlist_print(cl);
    cutlist_free(cl);
    vec_free(value_list);

    return 0;
}

void usage() {
    fprintf(stderr, "Invalid input. You must enter a positive integer for the rod length.\n");
    exit(1);
}
