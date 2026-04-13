#include <iostream>
using namespace std;

struct A{
    static float x;
    A(){
        x++;
    }
    void f();
};

struct B {
    static int x;
    B(){
        x++;
    }
};

// <datatyep> var_name = intialise


float A::x = 0;
int B::x = 0;

void A::f(){
    cout<<"print f"<<endl;
}

int main() {
    A a = A{};
    A a2 = A{};
    cout<<A::x<<endl;
    B b = B{};
    cout<<B::x<<endl;
    A a1 = A{};
    cout<<A::x<<endl;
    return 0;
}


