#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void store(int a[], int n, int x)
{
    if(n==0)
        return;

    store(a,n-1,x);

    if(a[n-1]==x)
    {
        ans.push_back(n-1);
    }
}

int main()
{
    int a[] = {1,2,3,4,4,5,4,7,8,8,8};
    int n=11;
    int x=5;

    store(a,n,x);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

    return 0;
}

