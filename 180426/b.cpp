#include <iostream>

using namespace std;


class Car{
    char  *col;
    string brand;
    float speed;
public:
     Car(char *col,string brand,float speed){
         std::cout <<"Constructor call"  << std::endl;
        this->col = new char[10];
        strcpy(this->col, col),this->brand = brand,this->speed = speed;
     }
    void getValue(){
        std::cout <<this->col<< " "<<this->brand<<" "<<this->speed  << std::endl;
    }
    void setColor(char *col){
        // this->col = col;
        strcpy(this->col, col);
    }
    void setSpeed(float speed){
        this->speed = speed;
    }
    Car& operator=(Car &obj){
        std::cout <<"Hello in objedct"  << std::endl;
        this->col = new char[10];
        strcpy(this->col, obj.col);
        this->brand = obj.brand;
        this->speed = obj.speed;
        return *this;
    }
    Car(){
    }
//     void freeMem(){
//         delete [] this->col;
//     }
    ~Car(){
        std::cout <<"Deconstructior call"  << std::endl;
        delete [] this->col;
    }

};

int main(){
    // Car ferrari;
    Car BMW = Car("RED","BMW",200.0);
    Car toyota = BMW;
    return 0;
}
