#include <iostream>

using namespace std;

class A {
    private:
    void foo() {
        cout<<"Hello world";
    }
    // void foo1() = 0;
};

// void A::foo1(){
//     std::cout <<"Hello inside A"  << std::endl;
// }
struct C: public A {
    public:
    void foo(){
        std::cout <<"Hello from C"  << std::endl;
    }
};
class B : public A
{
     void foo(){
         cout<<"inside b"<<endl;
     }
//     void foo1(){
//         std::cout <<"Hellio from A"  << std::endl;
//     }
};

// struct D : public B,C{
//
// };

// A stack(0x1000)  ----> [HEAP      0x10000 -> B()---->>> foo1() ---> foo()std::cout <<:"zhello world"  << std::endl;]
// a->foo() ->
// B stafk(0x1000) ---> HEAP ----> foo();
int main() {
    // B *b = new B(1,2,3);
    A *a = new B();
    a->foo();
    return 0;
}
