#include <iostream>


using namespace std;

bool f(int x){

}

int main() {
    int x;
    cin>>x;
    int arr[10] = {};

    // x -> int => 2^31 => 10^10
    // 32 => 10^9. ///  64 => 10^18
    int i=0;

    while(x){
      // cout<<x<<" ";
      // cout<<x%10<<" ";
      arr[i] = x%10;
      i++;
      x = x/10;
    }
    //  i = 3;

    // arr  => 3 2 1 i 0 0 0 0 0 0 
    // 123321 => 123321
    // arr[0] => arr[i-1]
    //  1 2 3 4 5 5 4 3 2 1
    // x = 12321
    // arr =  1 2 3 2 1 i 0 0 0 0

    //  arr[0] == arr[i-1]
    //  arr[1] == arr[i-2]
    //  arr[2] = arr[i-3]
    // i = 4
    //  arr[2] = arr[4 - 3]=> arr[1]
    //  arr[1] = arr[4-2] => arr[2]


    //  arr[p] == arr[i-(p+1)];

    // int p = 0;
    
    // cout<<i<< " "<< p <<" "<<endl;
    // i - (p+1)=> j - p
    
    int j = i - 1;
    
    i = 0;
    while(i<=j && arr[i]==arr[j]){
      i++,j--;
    }
    if(i<j)
    cout<<"it is not a pallindrome \n";
    else cout<<"it is a pallindrome \n";
    // else cout<<"it is not a pallindrome\n";
    // 123 -> 321 ===>  1.  2.    3.  => arr[3] = {1. 2. 3. }-> arr[2]-arr[1]-arr[0];
    // 123 => 123 === > 3. -> x % y ===> x/y jo riminder => proint 

    return 0;
}