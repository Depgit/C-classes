#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <compare>
using namespace std;

struct dep {
    int x;
    int y;
    auto operator<=>(const dep&) const  = default;
};

int main() {

    set<dep> st;
    st.insert({1,2});

//     st.insert({1,2});
//     st.insert({3,2});
//     st.insert({3,2});
//
//     for(auto it: st){
//         // std::cout <<it.first<< " {"<<it.second.x<< " "<<it.second.y<<"}"  << std::endl;
// //        std::cout <<it.x<< " "<<it.y  << std::endl;
//     }
//
    return 0;
}


