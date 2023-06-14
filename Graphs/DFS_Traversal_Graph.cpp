#include<bits/stdc++.h>
using namespace std;
int countConnectedComponents = 0;

void printDepthFirst(vector<vector<int> > v, int sv, vector<bool> &visited){
    cout<<sv<<" ";
    visited[sv] = true;
    int n = v.size();
    for(int i=0;i<n;i++){
        if(v[sv][i] == 1 && visited[i]==false){
            printDepthFirst(v,i, visited);
        }
    }
}

/*
the DFS function below has been created so that the printing works for disconnected graphs as well.
Simply explore all the vertices and check whether no vertex is left
*/

void DepthFirstSearch(vector<vector<int>> matrix)
{
    int n = matrix.size();
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            printDepthFirst(matrix,i,visited);
            countConnectedComponents++;
        }
    }
}

int main(){
   int n,e;
   cin>>n>>e;

   vector<vector<int> > matrix(n,vector<int>(n,0));

   for(int i=1;i<=e;i++){
    int fv,sv;
    cin>>fv>>sv;
    matrix[fv][sv] = 1;
    matrix[sv][fv] = 1;
   }
   cout<<"DFS Traversal: ";
   DepthFirstSearch(matrix);
   cout<<endl;
   cout<<"No. of connected components: "<<countConnectedComponents;
   return 0;
}
