#include<bits/stdc++.h>
using namespace std;
//top down approach - memorization
int MinSteps(int* arr, int n)
{
    if(n<=1)
    {
        arr[n] = 0;
    }

    //if output already exists, use the memory to avoid repetition
    if(arr[n]!=-1)
    {
        return arr[n];
    }

    int x = MinSteps(arr,n-1);
    int y = INT_MAX, z = INT_MAX;
    if(n%2 == 0)
    {
        y = MinSteps(arr,n/2);
    }

    if(n%3 == 0)
    {
        z = MinSteps(arr,n/3);
    }

    arr[n] = 1 + min(x,min(y,z));
    return arr[n];
}

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i] = -1;
    }
    cout<<MinSteps(arr,n);
    return 0;
}
