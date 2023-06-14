#include <bits/stdc++.h>
using namespace std;

void print(int a[], int n, int x)
{
    if(n==0)
        return;

    print(a,n-1,x);

    if(a[n-1]==x)
    {
        cout<<n-1<<" ";
    }
}

int main()
{
    int a[] = {1,2,3,4,4,5,4,7,8,8,8};
    int n=11;
    int x=8;

    print(a,n,x);

    return 0;
}

