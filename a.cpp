#include <iostream>

using namespace std;


int main() {
  int n = 102;// 1 + 0 + 2
  string s;
  s = to_string(n); // [1 -> 49  , 0-> 48 , 2->50]
  int ans = 0;
  for(auto it: s){
    int tem = it-48;
    ans += tem;
  }
  cout<<ans<<endl;
  return 0;
}
