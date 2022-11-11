#include <iostream>
using namespace std;

#include <iostream> using namespace std;
const float PI = 3.14;

class Shape{
    float xC, yC;
    public: 
    void setCenter(float x, float y){
        xC = x;
        yC = y;
    }
    void setx(float x){
        xC = x;
    }
    void sety(float y){
        yC = y;
    }
    float getx(){
        return xC;
    }
    float gety(){
        return yC;
    }
    void PrintCenter(){
        cout << "Center is (" << xC << ", " << yC << ")" << endl;
    }

};

class Circle: public Shape{
    float radius;
    public:
    Circle(float x, float y, float r){
        setx(x);
        sety(y);
        radius = r;
    }
    float area(){
        return PI * radius * radius;
    }
    void PrintArea(){
        cout << "Area is " << area() << endl;
    }

};

int main(){
    Shape F;
    F.setx(2);
    F.sety(5);
    F.PrintCenter();

    Circle C(20,30,7);
    C.PrintCenter();
    C.PrintArea();
    

    return 0;
    }