#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BTNode{
public:

    T data;
    BTNode* left;
    BTNode* right;

    BTNode(T data){
    this->data = data;
    left = NULL;
    right = NULL;
    }

    ~BTNode(){
        delete left;
        delete right;
    }


};

BTNode<int>* takeInputRecursive(){
     int rootData;
     cout<<"Enter data"<<endl;
     cin>>rootData;

     if(rootData==-1){
        return NULL;
     }
     BTNode<int>* root = new BTNode<int>(rootData);
     root->left = takeInputRecursive();
     root->right = takeInputRecursive();

      return root;
}

void LevelWisePrint(BTNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    queue<BTNode<int>*> q;
    q.push(root);
    cout<<root->data<<" ";

    while(!q.empty())
    {
        BTNode<int>* f = q.front();
        q.pop();

        if(root->left != NULL)
        {
            cout<<root->left->data<<" ";
            q.push(root->left);
        }

        if(root->right != NULL)
        {
            cout<<root->right->data<<" ";
            q.push(root->right);
        }

    }

    return;
}

BTNode<int>* LevelWiseInsertion()
{
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    BTNode<int>* root = new BTNode<int>(rootData);
    queue<BTNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BTNode<int>* f = q.front();
        q.pop();

         cout<<"Enter left child of "<<f->data<<endl;
         int leftChildData;
         cin>>leftChildData;
         if(leftChildData != -1){
            BTNode<int>* child = new BTNode<int>(leftChildData);
            q.push(child);
            f->left = child;
         }

         else {
            f->left = NULL;
         }
         cout<<"Enter right child of "<<f->data<<endl;
         int rightChildData;
         cin>>rightChildData;
         if(rightChildData != -1){
            BTNode<int>* child = new BTNode<int>(rightChildData);
            q.push(child);
            f->right = child;
         }

         else {
            f->right = NULL;
         }
    }
    return root;
}

void printBinaryTreeRecursive(BTNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<": ";
    if(root->left != NULL)
    {
        cout<<"Left Child "<<root->left->data<<", ";
    }

    if(root->right != NULL)
    {
        cout<<"RightChild "<<root->right->data;
    }

    cout<<endl;

    printBinaryTreeRecursive(root->left);
    printBinaryTreeRecursive(root->right);

}

int countNodes(BTNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void InOrderTraversal(BTNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}

bool searchNode(BTNode<int>* root, int key){
   if(root==NULL){
    return false;
   }
   if(root->data == key){
    return true;
   }

   return (searchNode(root->left,key) || searchNode(root->right,key));
}

int smallestNode(BTNode<int>* root)
{
    if(root == NULL)
        return INT_MAX;

    int leftChildvalue = smallestNode(root->left);
    int rightChildvalue = smallestNode(root->right);

    return min(root->data, min(leftChildvalue,rightChildvalue));
}

int largestNode(BTNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }

    int leftChildvalue = largestNode(root->left);
    int rightChildvalue = largestNode(root->right);

    return max(root->data, max(leftChildvalue,rightChildvalue));
}

int countLeafNodes(BTNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeafNodes(root->left)+countLeafNodes(root->right);
}

bool getPath(BTNode<int>* root,vector<int> &path, int value)
{
    if(root==NULL)
    {
        return false;
    }

    if(root->data == value)
    {
        path.push_back(root->data);
        return true;
    }

    path.push_back(root->data);

    bool left = getPath(root->left,path,value);
    bool right = getPath(root->right,path,value);

    if(left == true || right == true)
    {
        return true;  //this path is leads to our required node
    }

    path.pop_back();  //this is important as this particular child does not lead to our required value
    return false;   //returning false as this node is not our required node
}

int main()
{
    BTNode<int>* root = LevelWiseInsertion();
    cout<<endl;
    //printBinaryTreeRecursive(root);
    //LevelWisePrint(root);
    //cout<<"Total number of nodes are: "<<countNodes(root);
    cout<<"In Order Traversal: "<<endl;
    InOrderTraversal(root);
    cout<<endl;
    cout<<"Smallest Node is: "<<smallestNode(root)<<endl;
    cout<<"Largest Node is: "<<largestNode(root)<<endl;
    cout<<"Total number of leaf nodes are: "<<countLeafNodes(root)<<endl;

    vector<int> path;
    if(getPath(root,path,8))
    {
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<"->";
        }
    }

    else{
        cout<<"No path found because value 8 is not present"<<endl;
    }

    delete root;//to evoke the deletion of tree by using the destructor itself as a recursive function
    return 0;
}
