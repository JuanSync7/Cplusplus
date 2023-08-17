#ifndef MANGLER_FUNCTION_H
#define MANGLER_FUNCTION_H

#include "Permutation_DES.cpp"

using namespace std;

void mangler_function(int* left_half,int* right_half){
    
    int* expanded_plaintext = new int[HALF_PLAINTEXT_LEN];
    expanded_plaintext = expansion_permutation(right_half);
}

int* round_of_DES(int** permutated_plaintext_2D){
    //convert back to 1D array
    int i,j;
    int* permutated_plaintext;
    permutated_plaintext = new int[PLAINTEXT_LEN];
    for(i=0 ; i < BYTE ; i++){
        for(j=0 ; j < BYTE ; j++){
            permutated_plaintext[i+j] = permutated_plaintext_2D[i][j];
        }
    }

    int* left_half, *right_half;
    left_half = new int[HALF_PLAINTEXT_LEN];
    right_half = new int[HALF_PLAINTEXT_LEN];

    for(i=0 ; i < HALF_PLAINTEXT_LEN ; i++){
        right_half[i] = permutated_plaintext[i];
        left_half[i] = permutated_plaintext[i+(HALF_PLAINTEXT_LEN)];
    }

    mangler_function(left_half,right_half);
    return permutated_plaintext;
}

#endif