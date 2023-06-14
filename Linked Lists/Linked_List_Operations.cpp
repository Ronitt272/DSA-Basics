#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }
};

int length(Node *head)
{
    int count = 0;
    Node *temp = head;

    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int lengthrecursive(Node *head)
{
    if(head==NULL)
    {
        return 0;
    }

    return 1 + lengthrecursive(head->next);
}

bool searchinLL(Node *head,int element)
{
    if(head==NULL)
    {
        return false;
    }

    if(head->data==element)
        return true;

    return searchinLL(head->next,element);
}

Node* middleNode(Node *head) //leetcode
{
    Node *slow = head;
    Node *fast = head->next;

    while(fast!=NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast->next == NULL)
        return slow->next;

    else {
        return slow;
    }

}

Node* give_ith_node(Node *head, int i)
{
    Node *temp = head;

    if(i>=length(head))
    {
        Node *ptr = new Node();
        ptr->data = -1;
        return ptr;
    }

    int count = 0;
    while(temp!=NULL)
    {
        if(count == i)
        {
            return temp;
        }

        count++;
        temp = temp->next;
    }
}

Node* insertNthpos(Node *head, int data, int pos)
{
    Node *temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        if(pos == 0)
        {
            Node *ptr = new Node();
            ptr->data = data;
            head = ptr;
            head->next = temp;

            return head;
        }

        if(count == pos-1)
        {
            Node *temp2 = temp->next;
            Node *ptr = new Node();
            ptr->data = data;
            temp->next = ptr;
            ptr->next = temp2;

            return head;
        }

        temp = temp->next;
        count++;
    }



}


Node* deleteNthnode(Node *head, int pos)
{
    Node *temp = head;
    int count = 0;

    while(temp!=NULL)
    {
        if(pos == 0)
        {
            head = head->next;
            delete temp;
            return head;
        }

        if(count == pos-1)
        {
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
            return head;
        }

        temp = temp->next;
        count++;
    }

}

Node* mergesortedLLrec(Node *l1, Node *l2)
{
       if(l1==NULL)
            return l1;
       if(l2==NULL)
            return l2;

       Node *newHead = NULL;
       if(l1->data < l2->data)
       {
           newHead = l1;
           newHead->next = mergesortedLLrec(l1,l2->next);
       }

       else{
        newHead = l2;
        newHead->next = mergesortedLLrec(l1->next,l2);
       }

       return newHead;


}

Node* mergesortedLL(Node *l1, Node *l2)
{
       if(l1==NULL) return l2;
       if(l2==NULL) return l1;

       Node* finalHead = NULL;   /// head of the list to return

       if(l1->data < l2->data){
           finalHead = l1;
           l1 = l1->next;
       }else{
           finalHead = l2;
           l2 = l2->next;
       }
        Node *p = finalHead;   /// pointer to form new list

        while(l1 && l2){
            if(l1->data < l2->data){
                p->next = l1;   ///insertion at the tail
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1){
            p->next = l1;
        }else{
            p->next = l2;
        }
        return finalHead;

}


void print(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* takeInput()
{
    int m, i=1;
    cout<<"How many elements do you want in your Linked List?"<<endl;
    cin>>m;
    Node *head, *temp;
    while(i<=m)
    {
        Node *n1 = new Node();
        if(i==1)
        {
            head = n1;
            temp = n1;
        }
        else{
            temp->next = n1;
            temp = temp->next;
        }

        cin>>temp->data;
        i++;
    }

    return head;
}

Node* reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *n = head->next;

    if(n == NULL)
    {
        return head;
    }

    while(n!=NULL)
    {
     curr->next = prev;
     prev = curr;
     curr = n;
     head = curr;
     n = n->next;
    }

    head->next = prev;
    return head;

}

int main()
{

    //Node* l = takeInput();
   /* print(l);
    cout<<endl;
    //int n = length(l);
    int n = lengthrecursive(l);
    cout<<"The length of the linked list is: "<<n;
    int index;


    cout<<endl;
    cout<<"Which element you want to search for in Linked List ?"<<endl;
    int e;
    cin>>e;
    cout<<searchinLL(l,e)<<endl;

    Node *mid = middleNode(l);
    cout<<"The node at the middle is: "<<mid->data<<endl;

    cout<<"Reversed linked list is: "<<endl;
    Node* reversedLL = reverseLL(l);
    print(reversedLL);

    cout<<endl;
    cout<<"The node at which index do you want ?"<<endl;
    cin>>index;
    cout<<endl;
    Node *acquire = give_ith_node(l,index);
    cout<<acquire->data;
    cout<<endl;
    int d = 100,addindex;
    cout<<"In which index do you wish to add the new node ?"<<endl;
    cin>>addindex;

    Node *newLL = insertNthpos(l,d,addindex);
    print(newLL);
    cout<<endl;
    cout<<"The node at which index do you wish to delete ?"<<endl;
    int deleteindex;
    cin>>deleteindex;

    Node* updatedLL = deleteNthnode(newLL,deleteindex);
    print(updatedLL); */

    Node *l1 = takeInput();
    cout<<endl;
    Node *l2 = takeInput();
    cout<<endl;

    Node *mergedLL = mergesortedLL(l1,l2);
    print(mergedLL);

    return 0;

}
