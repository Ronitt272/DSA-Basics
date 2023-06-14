#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
   public:
       T data;
       vector<TreeNode<T>*> children;
       TreeNode(T data){
          this->data = data;
       }

       ~TreeNode(){

           for(int i=0;i<children.size();i++)
           {
               delete children[i]; //the delete function here initiates the recursion with the destructor itself
               //just rememberthe order: destructor called first, then TreeNode is deleted
           }
       }
};

void printTree(TreeNode<int>* root){
   if(root==NULL){
    return ;
   }
   cout<<root->data<<": ";
   for(int i=0;i<root->children.size();i++){
    cout<<root->children[i]->data<<" ,";
   }
   cout<<endl;

   for(int i=0;i<root->children.size();i++){
    printTree(root->children[i]);
   }
}

queue<TreeNode<int>*> L;

void LevelWisePrint(queue<TreeNode<int>*> L)
{
    cout<<"Level Wise Printing: "<<endl;

    while(!L.empty())
    {
        cout<<L.front()->data<<": ";

        for(int i=0;i<L.front()->children.size();i++)
        {
            cout<<L.front()->children[i]->data<<", ";
        }

        cout<<endl;
        L.pop();
    }

    return;

}

//In Pre Order Traversal, first print the root, and then print the children
void PreOrderTraversal(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";

    for(int i=0;i<root->children.size();i++)
    {
        PreOrderTraversal(root->children[i]);
    }
}

void PostOrderTraversal(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    for(int i=0;i<root->children.size();i++)
    {
        PostOrderTraversal(root->children[i]);
    }

    cout<<root->data<<" ";
    return;
}

void DeleteTree(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    for(int i=0;i<root->children.size();i++)
    {
        DeleteTree(root->children[i]);
    }

    delete root;
    return;
}

int countNodes = 0;
void countTreeNodes(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    countNodes++; // counts the root
    for(int i=0;i<root->children.size();i++)
    {
        countTreeNodes(root->children[i]);
    }

}

int heightTree(TreeNode<int>* root)
{
    int max_height = 0; //gives maximum height of a subtree.

    if(root == NULL) //if you don't include this edge case, if root is NULL, then
    {                //root->children used in the for loop below will give segmentation fault error, as root is NULL
        return 0;
    }

    for(int i = 0; i < root->children.size();i++)
    {
        int height = heightTree(root->children[i]);
        if(height > max_height)
        {
            max_height = height;
        }
    }

    return max_height + 1;
}

void printKthLevel(TreeNode<int>* root, int k)
{
    if(root == NULL)
    {
        return;
    }

    if(k == 0)  //when k hits 0, we are at the required Level of the tree
    {
        cout<<root->data<<" ";
    }

    for(int i=0;i<root->children.size();i++)
    {
        //the next statement uses recursion to go one level deep that is why k is reduced by 1
        printKthLevel(root->children[i],k-1); //recursion used for tree iteration
        //the loop works in such a way that for nodes on the same level, the value of k is the same
    }
}

int countleafnodes(TreeNode<int>* root)
{

    if(root->children.size()==0)
    {
        return 1;
    }

    int ans = 0;

    for(int i=0;i<root->children.size();i++)
    {
        ans+=countleafnodes(root->children[i]); //calling recursion on the children
    }

    return ans;

}

TreeNode<int>* LevelWiseInsertion(){
    int rootdata;
    cout<<"Enter the data for the root."<<endl;
    cin>>rootdata;

    TreeNode<int>* root = new TreeNode<int>(rootdata);

    queue<TreeNode<int>*> q;
    q.push(root);
    L.push(root);

    // The queue helps us keep track of the tree while inserting elements
    // After creating the new node, it must be connected to it's parent as well

    while(!q.empty())
    {
        TreeNode<int>* f = q.front();
        q.pop();

        int num;
        cout<<"Number of children of Node:"<<f->data<<" ?"<<endl;
        cin>>num;

        for(int i=1;i<=num; i++)
        {
            int d;
            cout<<"Enter the data of the "<<i<<"th child."<<endl;
            cin>>d;

            TreeNode<int>* child = new TreeNode<int>(d); //dynamic allocation of memory
            L.push(child);
            q.push(child);
            f->children.push_back(child);
        }

    }

    return root;

}

int main(){

  TreeNode<int>* root = LevelWiseInsertion();
  //printTree(root);
  LevelWisePrint(L);
  countTreeNodes(root);
  cout<<endl;
  cout<<"Total number of nodes in the tree: "<<countNodes;
  cout<<endl;
  cout<<"Height of the tree is: "<<heightTree(root);
  cout<<endl;
  cout<<"The nodes at Level 2 are: ";
  printKthLevel(root, 2);
  cout<<endl;
  cout<<"No. of leaf nodes are: "<<countleafnodes(root);
  cout<<endl;
  cout<<"Pre Order Traversal: ";
  PreOrderTraversal(root);
  cout<<"Post Order Traversal: ";
  PostOrderTraversal(root);
  //DeleteTree(root); //delete using the function
  delete root; //delete using the destructor

  return 0;
}
