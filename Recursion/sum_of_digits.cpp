#include<bits/stdc++.h>
using namespace std;

int sum(int n){
  ///Base Case
  if(n==0){
    return 0;
  }

  ///Recursive case
    return (n%10+sum(n/10));

}

int main(){
    int n;
    cin>>n;

    int ans = sum(n);
    cout<<ans;
    return 0;
}
