#include <algorithm>
#include <compare>
#include <iostream>

using namespace std;

typedef long long int ll;

struct foo {
  int x;
  // template<typename T>
  strong_ordering operator<=>(const foo &other) const { return x <=> other.x; }
};

int main() {
  int a[12];
  cout<<a[13]<<endl;
  foo f1;f1.x = 15;
  foo f2; f2.x = 13;
  cout<<(f1<=f2)<<endl;
  return 0;
}
