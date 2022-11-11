#include <iostream>
using namespace std;

class Person{ 
  protected:

  string name;

  public:
  friend class Student;
  friend class Professor;

  // Creating Person constructor
  Person(string n) {name = n;}
  virtual void print() { cout << "Person Name is " << name << "." <<endl;}
  
};

class Student: public Person{
  protected:

  float score;

  public:
  // Creating Student constructor and appending score as a new attribute
  Student(string n, float s) : Person(n){score = s;}
  void print() {cout << "Student Name is " <<name<< " and score is " << score << "." <<endl;}
};

class Professor: public Person{ 
  protected:
  

  int yearsev;

  public:
    // Creating Professor constructor and appending yearsev as a new attribute
  Professor(string n, int y) : Person(n){ yearsev = y;}

  void print() {cout<<"Professor Name is "<<name<<" and has "<<yearsev<<" years of service."<<endl;};
};

int main() {

  Person x("Mario");
  Person *p;
  p = &x;
  p->print();



  Student y("Ugo", 8.5);
  p = &y;
  p->print();



  Professor z("Tom", 5);
  p = &z;
  p->print();
  
}
