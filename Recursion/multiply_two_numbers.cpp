#include<bits/stdc++.h>
using namespace std;

int mult(int m, int n){
  ///Base Case
  if(n==0){
    return 0;
  }

  ///Recursive case
    return m+mult(m,n-1);

}

int main(){
    int m,n;
    cin>>m>>n;

    int ans = mult(m,n);
    cout<<ans;
    return 0;
}
