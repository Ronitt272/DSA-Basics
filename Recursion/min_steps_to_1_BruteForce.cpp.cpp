#include<bits/stdc++.h>
using namespace std;

int MinSteps(int n)
{
    if(n<=1) //base case
    {
        return 0;
    }
    int x=0,y=INT_MAX,z=INT_MAX;
    x = MinSteps(n-1);
    if(n%2 == 0)
    {
        y = MinSteps(n/2);
    }

    if(n%3 == 0)
    {
        z = MinSteps(n/3);
    }

    return 1+min(x,min(y,z));
}

int main()
{
    int n = 10;
    cout<<MinSteps(n);
    return 0;
}
