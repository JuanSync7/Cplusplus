#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <random>


#include "Permutation_DES.cpp"
#include "Subtraction_BOX_DES.cpp"
#include "Key_DES.cpp"

using namespace std;


int** create_2D_plaintext(int* plaintext){
    int i,j;
    int** plaintext_2D;
    plaintext_2D = new int*[BYTE];
    for(i=0 ; i < BYTE ; i++){
        plaintext_2D[i] = new int[BYTE];
        for(j=0 ; j < BYTE ; j++){
            plaintext_2D[i][j] = plaintext[i+j];
        }
    }
    return plaintext_2D;
}

int* to_binary(int& plaintext){
    int a_temp = plaintext;
    int* a_binary;
    a_binary = new int[PLAINTEXT_LEN];
    for(int i = 0 ; i < PLAINTEXT_LEN ; i++){
        //convert the decimals to binary '1' & '0'
        a_binary[i] = (a_temp % 2 == 0 ? 0 : 1);      
        a_temp /= 2;
    }
    return a_binary;
}

int main(){
    int input;
    int* key = create_key();

    cout << "input a number from 0 to 9.223*10^18" << endl;
    cin >> input;
    int* plaintext = to_binary(input);
    int** my2D_plaintext = create_2D_plaintext(plaintext);
    int** permutated_plaintext_2D = initial_permutation(my2D_plaintext);

    for(int i =0 ; i < 8 ; i++){
        Sub_box("S" + to_string(i));
    }

    return 0;
}