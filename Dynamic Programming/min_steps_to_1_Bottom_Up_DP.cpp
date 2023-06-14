#include<bits/stdc++.h>
using namespace std;
/*
In the code:
x = minimum steps to reach 1 from (n-1)
y = minimum steps to reach 1 from n/2
z = minimum steps to reach 1 from n/3

Time Complexity: O(n)
Space Complexity: O(n) - due to the DP array created
*/
int MinSteps(int n)
{
    int* arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 0;

    for(int i=2;i<=n;i++)
    {
        int x = arr[i-1];
        int y = INT_MAX;
        int z = INT_MAX;

        if(i%2 == 0)
        {
            y = arr[i/2];
        }

        if(i%3 == 0)
        {
            z = arr[i/3];
        }

        arr[i] = 1+min(x,min(y,z));
    }

    int minimum_steps = arr[n];
    delete[] arr;
    return arr[n];
}

int main()
{
    int n;
    cin>>n;

    cout<<MinSteps(n);

    return 0;
}
