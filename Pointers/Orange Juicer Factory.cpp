#include<iostream>
#include<string>
#include<random>
#include<cmath>

#define SEED_VALUE 123

using namespace std;


class Orange{

    public:
    Orange(){};
    Orange(string&);
    int get_juice(){return juice_ml;};
    
    private:
    int juice_ml;
    string orange_type;
    float diameter_size_cm;
    float sugar_content;

    protected:
};

Orange::Orange(string& orange_type){
    srand(time(0)); // initialize random number generator
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
    void harvesting(const int& today_harvest){this-> no_of_oranges += today_harvest;};

    private:
    string farm_name;
    int no_of_trees;
    string type_of_soil;
    int no_of_oranges;

    protected:
    string** weather;
};

Orange_Farm::Orange_Farm(const string& farm_name, const int& no_of_trees){
    this -> farm_name = farm_name;
    this -> no_of_trees = no_of_trees;
}

int main(){
    int no_of_farms_in_Reading = 5;
    int no_of_harvested_oranges;
    Orange* no_of_oranges = new Orange[no_of_harvested_oranges];
    Orange_Farm* list_of_orange_farms = new Orange_Farm[no_of_farms_in_Reading];

    for(int i= 0 ; i < no_of_farms_in_Reading ; i++){
        string temp = "Reading Orange Farm";
        list_of_orange_farms[i] = Orange_Farm(temp + to_string(i), 100);
    }

    cout << "Harvesting Time... " << endl;
    for(int i=0 ; i < no_of_farms_in_Reading ; i++){
        srand(time(0));
        list_of_orange_farms->harvesting(500+ rand()%1001); // no. of harvested oranges on that day
        cout << "Oranges: " << list_of_orange_farms->get_no_of_orange() << endl;
    }

    return 0;
}