#include<bits/stdc++.h>
using namespace std;
// optimized sort function for K-Sorted Array using Priority Queue
// size of priority queue is K at all times

vector<int> KSortedArray(vector<int> v, int k)
{
    priority_queue<int> q;
    vector<int> result;
    int start = 0;
    int it = k; //the iterator starts from the kth index
    for(int i=0;i<k;i++)  //for this loop, T = O(KlogK)
    {
        q.push(v[i]);
    }
    while(it<v.size())  //for this loop, T = O((N-K)logK)
    {
        result.push_back(q.top());
        q.pop();
        q.push(v[it]);
        it++;
    }

    while(!q.empty())  // for this loop, T = O(KlogK)
    {
        result.push_back(q.top());
        q.pop();
    }

    return result;
}

/* Time Complexity Analysis:
T = O(KlogK) + O((N-K)logK) + O(KlogK)
T = O(KlogK + NlogK + KlogK - KlogK)
T = O((N+K)logK)
Since, N>>K
T = O(NlogK)

In cases, where N>>>>>>K, logK is very very small
So, Time complexity can be approximated as: T = O(N)

Space Complexity:
In-place - O(K) = O(1) - due to priority queue
Additional Vector created - O(N)
*/
int main()
{
    vector<int> v = {10,15,6,4,5};
    int k = 2;
    vector<int> result = KSortedArray(v,k);
    cout<<"The resultant sorted array is: ";
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }

    cout<<endl;

    v = {10,12,6,7,9};
    k = 3;
    result = KSortedArray(v,k);
    cout<<"The resultant sorted array is: ";
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }

    return 0;
}
