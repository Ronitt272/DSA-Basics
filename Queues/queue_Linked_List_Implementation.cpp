#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T>* next;
};

template<typename T>
class Queue{
    T data;
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push(T ele)
    {
        Node<T> *n = new Node<T>;
        n->next = NULL;
        n->data = ele;

        if(size==0)
        {
            head = n;
            tail = n;
        }
        else {
            tail->next = n;
            tail = n;
        }
        size++;
    }

    void pop()
    {
        if(size==0)
        {
            cout<<"Queue is empty !"<<endl;
            return;
        }

        Node<T> *temp = head;
        head = temp->next;

        delete temp;
        size--;
    }

    bool isEmpty()
    {
        return size==0;
    }

    T front()
    {
        if(size==0)
        {
            cout<<"Queue is empty !"<<endl;
            return 0;
        }

        return head->data;
    }

    int getSize()
    {
        return size;
    }
};


int main()
{
    Queue<int> q;
    q.pop();
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.pop();
    q.pop();
    q.push(60);
    q.push(70);
    q.pop();

    cout<<"The front element is: "<<q.front()<<endl;
    cout<<"Queue empty status: "<<q.isEmpty()<<endl;
    cout<<"Size of the queue: "<<q.getSize()<<endl;


    return 0;
}
