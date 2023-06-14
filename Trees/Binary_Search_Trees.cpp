#include<iostream>
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

class Pair{
    public:
    BTNode<int>* head;
    BTNode<int>* tail;
};

class BST{
    BTNode<int>* root;

    void printTree(BTNode<int>* root){
   if(root==NULL){   /// base case
    return;
   }

   cout<<root->data<<": ";
   if(root->left!=NULL){
    cout<<"L"<<root->left->data;
   }

   if(root->right!=NULL){
    cout<<"R"<<root->right->data;
   }
   cout<<endl;

   printTree(root->left);
   printTree(root->right);
}
    bool hasData(BTNode<int>* node, int data){
        if(node==NULL){
            return false;
        }
        if(node->data == data){
            return true;
        }

        if(node->data > data){
            return hasData(node->left, data);
        }else{
           return hasData(node->right, data);
        }
    }

    BTNode<int>* insert(BTNode<int>* node, int data){
        if(node == NULL){
            BTNode<int> *n = new BTNode<int>(data);
            return n;
        }
        if(data < node->data){
            node->left = insert(node->left , data);
        }else{
           node->right = insert(node->right, data);
        }
        return node;
    }

    BTNode<int>* deleteTree(BTNode<int>* root, int data)
    {
        if(root == NULL)
        {
            return NULL;
        }

        if(root->data > data)
        {
            root->left = deleteTree(root->left, data);
        }
        else if(root->data < data)
        {
            root->right = deleteTree(root->right, data);
        }
        else{
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->right == NULL)
            {
                BTNode<int>* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }

            else if(root->left == NULL){
                BTNode<int>* temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }

            else{
                BTNode<int>* MinNode = root->right;
                while(MinNode->left != NULL)
                {
                    MinNode = MinNode->left;
                }
                int rightMin = MinNode->data;
                root->data = rightMin; //the root data updated with minimum value of right subtree
                root->right = deleteTree(root->right, rightMin); //this recursion is initiated to delete the minimum data from the right subtree
            }

            return root;
        }

        return root;
    }

    Pair converttoSortedLL(BTNode<int>* root)
    {
        if(root == NULL)
        {
            Pair p;
            p.head = NULL;
            p.tail = NULL;
            return p;
        }

        else if(root->left == NULL && root->right == NULL)
        {
            Pair p;
            p.head = root;
            p.tail = root;
            return p;
        }

        else if(root->left == NULL && root->right != NULL)
        {
            Pair p = converttoSortedLL(root->right);
            root->right = p.head;
            Pair ans;
            ans.head = root;
            ans.tail = p.tail;
            return ans;

        }
        else if(root->left != NULL && root->right == NULL)
        {
            Pair p = converttoSortedLL(root->left);
            p.tail->right = root;
            Pair ans;
            ans.head = p.head;
            ans.tail = root;
            return ans;
        }
        else{
            Pair p1 = converttoSortedLL(root->left);
            Pair p2 = converttoSortedLL(root->right);
            p1.tail->right = root;
            root->right = p2.head;
            Pair ans;
            ans.head = p1.head;
            ans.tail = p2.tail;
            return ans;
        }
    }

 public:
    BST(){
        root = NULL;
    }
    ~BST(){
       delete root;
    }

    void deleteData(int data){

    }
    void insert(int data){
       root = insert(root, data);
    }
    bool hasData(int data){
        return hasData(root, data);
    }
    void print(){
        printTree(root);
    }
    void Delete(int data)
    {
        root = deleteTree(root, data);
    }

    BTNode<int>* converttoSortedLL()
    {
        Pair p = converttoSortedLL(root);
        BTNode<int>* temp = p.head;  //variable to iterate over the LL
        while(temp->right!=NULL)
        {
            temp->left = NULL;
            temp = temp->right;
        }
        return p.head;
    }

};


int main(){
   BST b;
   b.insert(10);
   b.insert(5);
   b.insert(20);
   b.insert(7);
   b.insert(3);
   b.insert(15);
   cout<<endl;
   b.print();
   cout<<endl;
   //b.Delete(5);
   cout<<endl;
   b.print();
   int data;
   cout<<endl;
   cin>>data;
   cout<<b.hasData(data);
   cout<<endl;

   BTNode<int>* head = b.converttoSortedLL();
   while(head!=NULL)
   {
       cout<<head->data<<"->";
       head = head->right;
   }

   return 0;
}
