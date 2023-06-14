#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
bool checkpalin(int a[], int s, int e)
{
    if(s>=e)
        return true;

    checkpalin(a,s+1,e-1);

    if(a[s]!=a[e])
    {
        return false;
    }
}

int main()
{
    int a[] = {1,2,3,4,4,5,4,4,3,2,0};
    int n=11;
    bool ans;

    ans = checkpalin(a,0,n-1);
    if(ans){
        cout<<"String is palindrome.";
    }

    else{
        cout<<"String is not palindrome.";
    }
    return 0;
}
