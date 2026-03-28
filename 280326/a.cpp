#include <iostream>

using namespace std;

struct freq{
    int key;
    bool flag;
    // freq() {key =0, flag = false;}
    freq() {key = 0;flag = true;}
};



int main() {

    // freq fre = freq{}; // stack fre[- - - -] ->.  freq[] ---> fre
    freq *fre = new freq{};// freq();
    cout<<fre->flag<<endl;
    return 0;
}