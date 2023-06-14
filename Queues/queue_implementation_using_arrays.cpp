#include<bits/stdc++.h>
using namespace std;

class Queue{

    int *arr;
    int frontIndex;
    int nextIndex;
    int capacity;

    public:
    Queue()
    {
        capacity = 10;
        nextIndex = 0;
        frontIndex = -1;
        arr = new int[capacity];

    }

    Queue(int cap)
    {

        capacity = cap;
        nextIndex = 0;
        frontIndex = -1;
        arr = new int[capacity];
    }

    void push(int ele)
    {
        if(nextIndex == capacity)
        {
            cout<<"queue is full !"<<endl;
            return;
        }

        if(nextIndex == -1)
        {
            nextIndex = 0;
        }

        arr[nextIndex] = ele;
        nextIndex++;

        if(frontIndex == -1)
            frontIndex = 0;
    }

    void pop()
    {
        if(nextIndex == -1 || frontIndex == -1)
        {
            cout<<"queue is empty !"<<endl;
            return;
        }

        nextIndex--;
    }

    int size()
    {
        if(frontIndex==-1 || nextIndex == -1)
            return 0;

        return nextIndex - frontIndex;
    }

    bool isEmpty()
    {
        if(size()==0)
            return true;
        else{
            return false;
        }
    }

    int front()
    {
        if(frontIndex==-1 || nextIndex==-1)
            {
                cout<<"queue is empty"<<endl;
                return 0;
            }

        return arr[nextIndex-1];
    }

};

int main()
{
    Queue q(10);
    q.pop();
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.pop();
    q.pop();
    q.push(70);
    q.push(80);
    q.push(90);

    cout<<"size of queue: "<<q.size()<<endl;
    cout<<"queue empty status: "<<q.isEmpty()<<endl;
    cout<<q.front()<<endl;



    return 0;
}
