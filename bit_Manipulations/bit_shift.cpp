#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <typeinfo>
using namespace std;


int string_to_int(const string& decimal_num){
    int len = decimal_num.length();
    int integer = 0;
    float temp;
    for (int i = 0; i < len; i++) {
        temp = (int(decimal_num[i]) - '0')*pow(10,i);
        integer += temp;      
    }
    
    cout << "int:" << integer << endl;
    return integer;
}

string decimal_to_binary(const int& integer, const int& bit_size){
    char binary[bit_size];
    int temp = integer;
    cout << "temp:" << temp << endl;
    for(int i = bit_size-1; i >= 0; i--){
        binary[i] = char(temp%(2) + '0');
        temp = temp/2;
        cout << "temp:"<< temp << endl;
    }

    cout << "binary:" << binary << endl;
    return binary;
}


int bit_shift_left(unsigned char& bits, const int& shift){
    
    //string temp = bits.substr(shift,size);
    bits = (bits << shift);
    
    // must be return as int to show correct decimal representation
    return int(bits);
}

//function overloading c++
int bit_shift_left(int& bits, const int& shift){

    bits = (bits << shift);

    return bits;
}


int bit_shift_right(unsigned char& bits, const int& shift){
    
    //string temp = bits.substr(shift,size);
    bits = (bits << shift);
    
    // must be return as int to show correct decimal representation
    return int(bits);
}

//function overloading c++
int bit_shift_right(int& bits, const int& shift){

    bits = (bits << shift);

    return bits;
}

int main(){

    string decimalNumber;
    char cont[10];
    char* ptr = cont;
    while (getline(cin, decimalNumber)) {
        // Convert decimal number to 32-bit binary representation
        //string binaryNumber = bitset<32>(stoi(decimalNumber)).to_string();;
        unsigned char c = 5;
        cout << "bit_shift:" << bit_shift_left(c,1) << endl;
        int d = 5;
         cout << "bit_shift_int:" << bit_shift_left(d,1) << endl;
        string binaryNumber = decimal_to_binary(string_to_int(decimalNumber),32);

        cout << "To Continue type \"Y\"" << endl;
        cin >> cont;
        cout << cont  << endl;
        if(tolower(ptr[2]) == 'y'){
            continue;
        }
        else{
            cout << "Thanks for using bit-shifter." << endl;
            break;          
        }
    }
    return 0;
}

