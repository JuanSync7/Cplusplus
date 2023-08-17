#ifndef DES_KEY_H
#define DES_KEY_H

#include <iostream>
#include <string>

#define SEED_VALUE 123
#define KEY_LEN 64
#define ROUND_KEY_LEN 48
#define HALF_KEY_LEN 32

using namespace std;

int* create_key(){
    int* key;
    key = new int[KEY_LEN];
    int i;
    srand(SEED_VALUE);
    for(i=0; i < KEY_LEN ; i++){
        key[i] = (rand() % 2);
    }
    return key;
}

int* create_round_key(int* key){
    int* round_key = new int[ROUND_KEY_LEN];
    int i;

    int* left_half, *right_half;
    left_half = new int[HALF_KEY_LEN];
    right_half = new int[HALF_KEY_LEN];

    for(i=0 ; i < HALF_KEY_LEN ; i++){
        right_half[i] = key[i];
        left_half[i] = key[i+(HALF_KEY_LEN)];
    }

}

#endif