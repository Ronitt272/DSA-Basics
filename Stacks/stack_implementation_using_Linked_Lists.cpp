#include<iostream>
using namespace std;

class Stack{
    int data;
    Stack *next;
    Stack *head;

public:
    Stack(){
        head = NULL;
    }

    Stack(int ele)
    {
        Stack *n = new Stack();
        n->data = ele;
        n->next = NULL;
        head = n;
    }

    void push(int ele)
    {
        Stack *s = new Stack();
        Stack *temp = head;
        s->data = ele;
        s->next = temp;
        head = s;
    }

    void pop()
    {
        if(head == NULL)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }

        Stack *temp = head;
        head = head->next;
        delete temp;
    }

    int size()
    {
        Stack *temp = head;
        int count = 0;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    bool isEmpty()
    {
        if(head == NULL)
        {
            return true;
        }

        else {
            return false;
        }
    }

    int top()
    {
        if(head == NULL)
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return head->data;
    }

} ;

int main()
{
    Stack s(10);
    s.pop();
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.pop();
    s.pop();

    cout<<"size of stack: "<<s.size()<<endl;
    cout<<"Stack empty status: "<<s.isEmpty()<<endl;
    cout<<s.top()<<endl;



    return 0;
}
