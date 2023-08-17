#include <iostream>

#ifndef PERMUTATION_H
#define PERMUTATION_H


#include "Key_DES.cpp"

// defining constants
#define PLAINTEXT_LEN 64
#define HALF_PLAINTEXT_LEN 32
#define BYTE 8
#define HALF 2
#define EXPAND_PLAINTEXT_LEN 48



using namespace std;

int** initial_permutation(int** plaintext_2D){
    int i,j,k,l;
    int** permutated_plaintext_2D;
    permutated_plaintext_2D = new int*[BYTE];
    for(i=0 ; i < BYTE ; i++){
        permutated_plaintext_2D[i] = new int[BYTE];
        k = 7;
        for(j=0 ; j < BYTE; j++){
            permutated_plaintext_2D[i][j] = plaintext_2D[k][l];
            k = k-1;
        }
        l = l+2;
        if(l > 8){
            l = 1;
        }
    }
    return permutated_plaintext_2D;
}


int* expansion_permutation(int* right_half){
    int i,j;
    // j is used such that whenever the expanded permutation places a "new" bit in pos. 0,5,6,10...., the index of the right half is "paused".
    int* expanded_permutated_plaintext;
    for(i=1 ;  i < EXPAND_PLAINTEXT_LEN ; i++){
        if(i % 5 == 0){
            expanded_permutated_plaintext[i] = right_half[i-1];
            j = j+1; 
        }
        else if(i % 6 == 0){
            expanded_permutated_plaintext[i] = right_half[i-3];
            j = j+1;
        }    
        else{
            expanded_permutated_plaintext[i] = right_half[i-1-j];
        }
    }
    expanded_permutated_plaintext[0] = right_half[HALF-1];
    expanded_permutated_plaintext[EXPAND_PLAINTEXT_LEN] = right_half[0];

    return expanded_permutated_plaintext;
}

int* permuted_choice_1(int* key){
    int* temp = new int[HALF_KEY_LEN];
    int* temp1 = new int[HALF_KEY_LEN];

    for(int i= 0 ; i < HALF_KEY_LEN ; i++){
        temp[i] = key[i+1];
        temp1[i+1] = key[i+2];
    }
    temp1[0] = key[0];
}
#endif

