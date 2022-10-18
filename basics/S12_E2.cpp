/* Exercise Instructions

Write a program able to:
• Create a class Vehicle, with public members (only data): int tankcapacity, int passengers, int kmperliter;
• Create two objects of Vehicle;
• Enter the values of the object fields;
• Calculate and show how many km you will drive with full tank.You will need to use a function in order to manage the object fields loading.

*/
#include <iostream>
using namespace std; 

class Vehicle{
    private: 

    public: 
    int fuelMax;
    int passengers;
    int horsePower;
    double mpg;
    string brand; 
    
    double range(){return fuelMax*mpg;}; 

    Vehicle(string b, int f, int p, double g, int hp); // declaring the constructor for a vehicle

};

Vehicle::Vehicle(string b, int f, int p, double g, int hp){
    brand = b; 
    fuelMax = f; 
    passengers = p; 
    mpg =g;

}

 


int main(){

    Vehicle car("Peugeot 208", 11, 5, 60.1, 100 );

    cout<<"The range on the "<< car.brand<< " is around "<< car.range() <<" miles"<<endl;

    cout<<"The range on the "<< car.brand<< " is around "<< car.range() * 1.6 <<" km"<<endl; 

    Vehicle moped("Vespa", 2, 5, 60, 12 );

    cout<<"The range on the "<< moped.brand<< " is around "<< moped.range() <<" miles"<<endl;
    cout<<"The range on the "<< moped.brand<< " is around "<< moped.range() * 1.6 <<" km"<<endl; 
    
    return 0;


}