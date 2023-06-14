#include<bits/stdc++.h>
using namespace std;

void makeSet(int N, int parent[])
{
    for(int i=1;i<=N;i++)
    {
        parent[i] = i;
    }
}

int findParent(int i, int parent[])
{
    while(parent[i]!=i)
    {
        i = parent[i];
    }

    return i;
}

bool cmp(vector<int> A, vector<int> B)
{
    return A[2] < B[2];
}

int MST(int N, vector<vector<int>>& edges)
{
    sort(edges.begin(),edges.end(),cmp);
    int parent[N+1];
    int minCost = 0;
    makeSet(N,parent);

    for(int i=1;i<=edges.size();i++)
    {
        int s = edges[i-1][0];
        int d = edges[i-1][1];

        int a = findParent(s,parent);
        int b = findParent(d,parent);

        if(a != b)
        {
            minCost = minCost + edges[i-1][2];
            parent[b] = a;
        }
    }

    return minCost;

}

int main()
{
    int N = 4; //number of vertices or nodes in the graph
    vector<vector<int>> edges ={{1,2,1},{2,3,4},{1,4,3},{4,3,2},{1,3,10}}; //the edges of the graph, 0th column - source vertex, 1st column - destination vertex, 2nd column - edge weight or cost
    cout<<"The cost of Minimum Spanning Tree is: "<<MST(N,edges);
    return 0;
}
