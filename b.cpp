#include <iostream>

using namespace std;


void twosum(int a[],int n){
    for (int i = 0; i < n; i++){ 
        a[i] = a[i] + i;
    }
}
      
int main(){
  int n; 
  cin>> n;
  int a[n];
//   for (int i = 0; i < n; i++)
//   {
//     cin >> a[i];
//   }

  for(int &i: a)
    cin>>i;






    // for(init ; condition ; jump)
    // 0 -> n ------- n sari value pe itirate 
    // 0 index add adree ja ke cin >> &a[0]+4;
    // range(1,10) -> 1 2 3 4 5 6 .. 9
    // for(i : range(1,n)) range - 1 - n
    // for(a) // a -> iterator 
    // for(a(0,n))
    // for (a) cin >> iter;
    // for(auto iter : a) -> me a iter -> mera iter 
    //  for (auto i : a) -> i mera iterator and a jispe iterate 
    
    for(auto &i: a){
        cin >> i; // 0x0004 -> 1 // 0x0008 -> 2
    }


    // a[n] -> 0x0004 -> a[0] --------------- a[n-1];
    // range a[0] -> add -> a[n-1] add &(a + 4) -> a[4] 
    // i = &(a + 4) -> cin >> i -> cin >> *(a + 4) 

    // for ( auto &val : arr){ // f
//  for ( auto val = a[i] -> auto val )
    // }

for (auto val : a) {}
    // int *b = a;
    // a[5] = 5 -> a[6] = -1093ru2039;
// for () auto val = &a;cin >> val;
//  for () auto val = &(a+1); 
//  for () auto val = &(a + 2);
// for (auto i  : a)-> a ->int n * 4 byter iter -> a[0] 0x0004 -> 
for(auto &val : a)cin >> val;
// a = &a[0] = *a;



  twosum(a,n);
  for (int i= 0; i < n; i++){
    cout << a[i] << " "; 
  }
    return 0;
}
