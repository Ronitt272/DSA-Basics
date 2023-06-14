#include<bits/stdc++.h>
using namespace std;
int countConnectedComponents = 0;

void printBreadthFirst(vector<vector<int> > v, int sv, vector<bool>& visited){
    int n = v.size();
     queue<int> q;
     q.push(sv);
     visited[sv] = true;

     while(!q.empty()){
        int cv = q.front();
        q.pop();
        cout<<cv<<" ";
        for(int i=0;i<n;i++){
            if(v[cv][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
     }
}
/*
works for disconnected graphs as well,since all the vertices are explored
*/
void BreadthFirstSearch(vector<vector<int>> matrix)
{
    int n = matrix.size(); //gives the number of vertices
    vector<bool> visited(n,false);

    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            printBreadthFirst(matrix,i,visited);
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

   cout<<"BFS: ";
   BreadthFirstSearch(matrix);
   cout<<endl;
   cout<<"No. of connected components: "<<countConnectedComponents;
   return 0;
}
