#include<bits/stdc++.h>
using namespace std;

int towerofhanoi(int n)
{
        if(n == 0)
        {
        return 0;
        }

        return towerofhanoi(n-1) + 1 + towerofhanoi(n-1);

}

void printSteps(int n, char s, char h, char d)
{
    if(n==0)
    {
        return;
    }

    printSteps(n-1,s,d,h);
    cout<<"Moving disk "<<n<<" from "<<s<<" to "<<d<<endl;
    printSteps(n-1,h,s,d);

}

int main()
{
    int n;
    cin>>n;
    cout<<endl;
    //cout<<"total number of steps required: ";
    //int steps = towerofhanoi(n);
    //cout<<steps;
    printSteps(n,'A','B','C');
    return 0;
}
