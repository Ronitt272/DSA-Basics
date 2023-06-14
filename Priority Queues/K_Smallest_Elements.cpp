#include<bits/stdc++.h>
using namespace std;
/*
This approach is optimized
Using sorting approach: T = O(NlogN)
This approach uses Maximum Priority Queues
T = O(NlogK) - due to insertions into the priority queue, which at all times will have K elements
S = O(K) - due to priority queue created

For finding K smallest elements, use max PQ
For finding K largest elements, use min PQ
*/
priority_queue<int> KSmallestElements(vector<int> v, int k)
{
    priority_queue<int> q;
    for(int i=0;i<k;i++)
    {
        q.push(v[i]);
    }

    for(int index = k;index<v.size();index++)
    {
        if(q.top() > v[index])
        {
            q.push(v[index]);
            q.pop();
        }
    }

    return q;
}

int main()
{
    vector<int> v = {8,5,10,12,0,1,6,9};
    int k = 4;
    priority_queue<int> result = KSmallestElements(v,k);
    cout<<endl;
    cout<<"The K smallest elements are: ";
    while(!result.empty())
    {
        cout<<result.top()<<" ";
        result.pop();
    }

    return 0;
}
