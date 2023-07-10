#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

int string_to_int(const string& decimal_num){
    cout << decimal_num << endl;
    int len = decimal_num.length();
    int integer = 0;
    double temp = 0.0;
    for (int i = 0; i < len; i++) {
        temp = (decimal_num[i] - '0')*(pow(10.0,float(i)));
        integer += temp;
        cout << "integer:: " << integer << endl;     
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

int countBitTwins(const string& binaryNumber) {
    int count = 0;
    int index = 0;
    int len = binaryNumber.length();
    while (index < len - 3) {
        if (binaryNumber.substr(index, 4) == "0110") {
            count++;
        }
        index++;
    }
    return count;
}

int main() {
    string decimalNumber;
    while (getline(cin, decimalNumber)) {
        // Convert decimal number to 32-bit binary representation
        //string binaryNumber = bitset<32>(stoi(decimalNumber)).to_string();

        string binaryNumber = decimal_to_binary(string_to_int(decimalNumber),32);
        // Count bit-twins in the binary representation
        int twinsCount = countBitTwins(binaryNumber);

        // Print the result
        cout << "Number of bit-twins: " << twinsCount << endl;
        return 0;
    }

   
}