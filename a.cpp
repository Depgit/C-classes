#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

struct dep {
    int x;
    float y;
    ll z;
};

union dep1 {
    int x;
    float y;
    ll z;
};

// ipv4 255.255.255.255
// ipv6 ie:oi:09:93:38
//
// 64 byte -> 32 64

void f(int &x){// p => 0x45---->  x-> 0x05 *p => *x => p address -> x
    x = 100;
    std::cout <<"x ki value "<<x  << std::endl;
}

int main() {
    int x;std::cin >> x;
    bool arr[32] = {0};
    int i=0;
    while(x){
        arr[i] = x%2;
        i++;
        x = x / 2;
    }
    for(auto i: arr)std::cout << i<< " "  ;
    return 0;
}

