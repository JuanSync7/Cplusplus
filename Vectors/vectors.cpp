#include<iostream>
#include<vector>
#include<string>


//Different type of vectors.

int main(){

    //think of vector like a "as variables in a class object".

    std::vector<int> vec1; //this is a vector that hold int elements
    vec1.push_back(1);
    
    std::vector<std::string> vec2; // this is a vector that hold string elements
    vec2.push_back("Hello.");

    std::vector<int*> vec3; //this is a vector that hold pointers of integers
    int int1 = 1;
    int *ptr_int1 = &int1; //local declaration of a pointer in main
    vec3.push_back(ptr_int1);

    std::vector<std::vector<int>> vec4; // this is a 2D vector with integer elements
    vec4[0].push_back(10); // placed "10" at end of the first row
    vec4[1].push_back(20); // placed "20" at end of the second row

    std::vector<std::vector<int>>* ptr_2D_vec = new std::vector<std::vector<int>>;
    ptr_2D_vec = &vec4; // set the pointer to the memory address of vec4[0][0]

    std::vector<int>* ptr_vec = new std::vector<int>; // create a pointer for a vector
    ptr_vec = &vec1; // set ptr_vec to the memory address of "vec1"

    delete ptr_vec; // free the memory
    delete ptr_2D_vec; // free the memory

    return 0;
}
