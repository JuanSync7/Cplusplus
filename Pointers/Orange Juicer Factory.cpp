#include<iostream>
#include<string>
#include<random>
#include<cmath>

#define SEED_VALUE 123
#define CITIES 5

using namespace std;


class Orange{

    public:
    Orange(){};
    Orange(const string&);
    int get_juice(){return juice_ml;};
    
    private:
    int juice_ml;
    string orange_type;
    float diameter_size_cm;
    float sugar_content;

    protected:
};

Orange::Orange(const string& orange_type){
    srand(SEED_VALUE); // initialize random number generator
    this -> orange_type = orange_type; // type of orange
    this -> diameter_size_cm = 4.7 + (float)(rand()%5); // average diameter of an orange is 6.7cm. Thus, we create a range of sizes between 4.7cm to 8.7cm
    this -> juice_ml = (4/3*3.142*pow(diameter_size_cm,3))* (1/(12-(float)(rand()%4))); //average orange juice is 1ml per 10cm^3, thus we create a range of 1ml per 8cm^3 to 12cm^3
}
class Orange_Farm: public Orange{

    public:
    Orange_Farm(){};
    Orange_Farm(const string&, const int&);
    void change_farm_name(const string& x){farm_name = x;};
    int get_no_of_orange(){return no_of_oranges;};
    void harvesting(const int& today_harvest){this-> no_of_oranges = today_harvest;};
    Orange* oranges_data();

    private:
    string farm_name;
    int no_of_trees;
    string type_of_soil;
    int no_of_oranges;
    Orange* oranges; // create a pointer for the array to store data of the oranges

    protected:
    string** weather;
};

Orange_Farm::Orange_Farm(const string& farm_name, const int& no_of_trees){
    this -> farm_name = farm_name;
    this -> no_of_trees = no_of_trees;
}

Orange* Orange_Farm::oranges_data(){
    this -> oranges = new Orange[this -> no_of_oranges];
    for(int i=0 ; i < this -> no_of_oranges ; i++){
        oranges[i] = Orange("Valencia"); // create the oranges
    }
    return oranges;
}

int main(){
    int no_of_farms_in_each_city = 5;

    Orange_Farm** list_of_orange_farms = new Orange_Farm*[CITIES];
    Orange** orange_juice = new Orange*[25];
   
    for(int i= 0 ; i < CITIES ; i++){
        list_of_orange_farms[i] = new Orange_Farm[no_of_farms_in_each_city];
        for(int j=0 ; j <no_of_farms_in_each_city; j++){
            string temp = "Orange Farm_";
            list_of_orange_farms[i][j] = Orange_Farm(temp + to_string(i+j), 100);
        }
        
    }

    cout << "Harvesting Time... " << endl;
    for(int i=0 ; i < CITIES ; i++){
        for(int j=0 ; j <no_of_farms_in_each_city; j++){
            srand(i*10+j*5);
            list_of_orange_farms[i][j].harvesting(500 + rand()%1001); // no. of harvested oranges on that day between 500 to 1500
            cout << "i:" + to_string(i) + "j:" + to_string(j) << "Oranges: " << list_of_orange_farms[i][j].get_no_of_orange() << endl;

            orange_juice[i+j] = list_of_orange_farms[i][j].oranges_data();
            cout << "JUICE: " << orange_juice[i][25] << endl;
        }
    }
    int asd = orange_juice[10][10].get_juice();
    cout << "JUICE: " << &orange_juice[1] << endl;


    return 0;
}