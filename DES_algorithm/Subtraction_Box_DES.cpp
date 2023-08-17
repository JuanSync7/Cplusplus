#ifndef SUB_BOX_H
#define SUB_BOX_H

#include <iostream>
#include <string>

using namespace std;

#define LIST_SIZE 16
#define SEED_VALUE 1000
#define SHUFFLES 100
#define ROW 4
#define COLUMN 16

class Sub_box{

    public:
    Sub_box(){};
    Sub_box(string);
    void create_list();
    string get_sub_box_name(){return Sub_box_name;};
    int collect_value(int i, int j){return list_array[i][j];};

    private:
    int** list_array = new int*[15];
    void shuffle_list();
    string Sub_box_name;
    
};

Sub_box::Sub_box(string name){
    this -> Sub_box_name = name;
}

void Sub_box::shuffle_list(){
    srand(SEED_VALUE);
    int i,j,temp,temp_index,temp_index2;
    // shuffle the list 100 times
    for(i=0 ; i < ROW ; i++){
        list_array[i] = new int[15];
        for(j=0 ; j < SHUFFLES ; j++){
            temp_index = rand()%15; // index of first element
            temp = list_array[i][temp_index]; // store first element in temp variable
            temp_index2 = rand()%15; // index of second element 
            this -> list_array[i][temp_index] = list_array[i][temp_index2]; // replace first element in list with second element
            this -> list_array[i][temp_index2] = temp; // replace second element in list with first element
        }
    }
}

void Sub_box::create_list(){
    int i,j;
    for(i=0 ; i < ROW ; i++){
        for(j=0 ; j < COLUMN; j++){
            this -> list_array[i][j] = j;
        }
    }
    shuffle_list();
}


#endif