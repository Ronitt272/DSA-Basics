#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.pop();
    q.pop();
    q.push(60);
    q.pop();

    stack<int> s;

    while(q.size()!=0)
    {
        cout<<q.front()<<" ";
        s.push(q.front());
        q.pop();
    }

    cout<<endl;

    while(s.size()!=0)
    {
        cout<<s.top()<<" ";
        s.pop();
    }


    return 0;
}
