/* Exercise Instructions

Write a program in C++ able to
• Load an array A[4]
• Load an array B[4]
• Create an array C[4] as A+B (C[i]=A[i]+B[i]
• Show C[4]

Use the following functions:
void loadarray(int px[], int pn);
void showarray(int px[], int pn);
void sumarray(int px[], int py[],int pz[],int pn);

*/

#include <iostream>

using namespace std;


int loadarray(int px[], int pn){ // usually u pass the size as a parameter, you could also addpx rather than px[]
    for(int i=0;i<pn ;i++)
        px[i]=i+1;
    return 0;
};

void showarray(int px[], int pn){

    for(int i = 0; i< pn;i++)
    cout<<px[i];
}

void summary(int px[], int py[], int pz[], int pn){
    for(int j=0; j<pn;j++){
        pz[j]=py[j]+px[j];}
}

int main() {
  const int size=4;
  int A[size];
  int B[size];
  int C[size];


  loadarray(A, size);
  loadarray(B, size);
  summary(A,B,C,size);

  cout<<"if you add     "; 
  showarray(A,size); 
  cout<<"+";
  showarray(B,size); 
  cout<<endl; 
  cout<< "You get:   ";
  showarray(C,size);
  cout<< endl;

  return 0;
}