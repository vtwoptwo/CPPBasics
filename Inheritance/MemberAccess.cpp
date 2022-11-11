#include <iostream>
using namespace std;


class Shape{
    double width;
    double height;
public:
    void showDim(){
        cout << "Width and height are " << width << " and " << height << endl;
    }
    void setDim(double w, double h){
        width = w;
        height = h;
    }

    double accessw(){
        return width;
    }
    double accessh(){
        return height;
    }
    


};


class Triangle: public Shape{
    public:
    double width = accessw();
    double height = accessh();

    char Type[20];
    double area(){
        return width * height / 2;
    }
    void showType(){
        cout << "Type is " << Type << endl;
    }
};
