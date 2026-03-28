#include <iostream>
using namespace std;

struct f{
    bool flag;
    struct nested{
        bool flag1;
        struct nested1 {
            bool flag2;
        };
    };
    nested n = nested{};
    void check(nested n = nested{});
};

void f::check(nested n){
    cout<<"hello "<<endl;
}

void check(int n);


int main() {
    f fre = f{};
    // std::cout<<endl;
    // fre.nested1
    f::nested::nested1 n = f::nested::nested1{};
    fre.check();
    check(5);
    // cout<<n.flag2<<endl; 
    return 0;
}


void check(int n){
    cout<<n<<endl;
}
