#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct freq{
    int key;
    int value;
};
// freq arr[10] -> map logical 

int main() {
    // 2 2 1 1 3 --> 3
    // {[2,2],[1,2],[3,1]} --> ans
    //  a[i] == 10^5;
    // int a[10];  ---> a name array hai jiska type int jo ki 10 length
    // string a[10]. -> a name ka string hai jo ki 10 length 
    // float a[10] ==> 10 lenght float 
    // freq a[10]. ==> 10 length ka freq 
    // freq banayi mujhe iska array chahiye jiska ander value store {[2,2],[1,2],[3,1]}
    // arr[value]++; 
    // 0 0 0 0 0 -> {i(2),3,2,3,1}
    // 0 0 1 0 0 -> {2, i(3), 2, 3, 1}

    // {
    //     2 -> 2,
    //     3 -> 2,
    //     1 -> 1
    // }

    // bola a[i] <= 100 always 
    // map<int,int> mp;
    // {2,3,2,3,1}
    // map[2]+=1
    // map{}
    // map{{2,1}}
    // map[3]++ ----> map{{2,1},{3,1}};
    // map[2]++ ----> map[2] if exist ---> map[2]++ ===> map{{2,2},{3,1}};
    // map[3]++ ----> map[3] search --> map[3]++ ==> map{{2,2},{3,2}}
    //  map[1]++ --> not found =====> map{{2,2},{3,2}, {1,1}};
    //  iterate kar loo map pe and koi bhi value agar 1 hai to usjka key ans 


    map<int,int> mp; // {{1,0},{3,0},{5,0}} 
    vector<int> arr{2,2,3,3,4,1,4,1,5}; // input dia hua h 
    int n = arr.size();
    for(int i=0;i<n;i++){
        mp[arr[i]] = mp[arr[i]] +1;
    }
    cout<<"{"<<endl;
    for(auto it: mp){
        cout<<"{"<<it.first<<" "<<it.second<<"}"<<endl;
        if(it.second == 1){
            cout<<it.first<<endl;return 0;
        }
    }
    cout<<"}"<<endl;

    // const int n = 10;
    // int arr[n]; // 


    

    return 0;
}