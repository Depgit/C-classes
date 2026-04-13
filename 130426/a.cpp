#include <iostream>
using namespace std;



// struct A{
//     int x;
//     // A(int y){
//     //     x = y;
//     // }
//     A(int y) : x(y) {
//         cout<<"constructor called"<<endl;
//     }
//     void f(int x){
//         cout<<"print f"<<endl;
//     }
// };

// [this ------> A(x)]
// A(5). x = 5; 5 = 5;   ======> this->x = 5;

// struct A
// {
//     int x = 0;
//     A(int x) {
//         // x = 5 ==> 5 = 5;
//         this->x = x; // a.x = 5;   a1.x = 5;
//         cout << "constructor called" << endl;
//     }
// };

struct A{
private:
    int x;
protected:
    int y;
public:
    int z;
    A(int x) {
        this->x= x;
        cout<<"constructor called"<<endl;
    }
    void print(){
        cout<<"x = "<<x<<endl;
        cout<<"y = "<<y<<endl;
        cout<<"z = "<<z<<endl;
    }
};

struct B : public A{
    B(int y,int x) : A(x) {
        this->y = y;
    }
    void inc(){
        this->y++;
    }
};





int main() { // - - - -
    A a = A{5};
    cout<<a.z<<endl;
    cout<<a.z<<endl;
    cout<<a.z<<endl;
    B b(10,15);
    cout<<b.z<<endl;
    a.print();
    b.print();
    return 0;
}


