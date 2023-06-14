#include<bits/stdc++.h>
using namespace std;

struct Node{
        int data;
        Node *next;
    };

    int lengthLL(Node *head)
    {
        int count = 1;
        Node *temp = head->next;

        while(temp!=head)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    Node* createLL(int n, int k)
    {
        Node *head = new Node;
        head->data = 1;
        Node *temp = head;

        for(int i=2;i<=n;i++)
        {
            Node *temp2 = new Node;
            temp2->data = i;
            temp->next = temp2;
            temp = temp->next;
        }

        temp->next = head;

        return head;
    }

    Node* givewinner(Node *head, int k)
    {
        int len = lengthLL(head);

        while(len!=1)
        {
            Node *temp = head;
            for(int i=1;i<=k-2;i++)
            {
                temp = temp->next;
            }

            Node *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
            temp = temp->next;
            head = temp;

            len--;
        }

        return head;
    }

    int findTheWinner(int n, int k) {

        if(n==1)
            return 1;

        if(k==1)
            return n;

        Node *circle = createLL(n,k);

        Node *winner = givewinner(circle,k);

        return winner->data;

    }


int main()
{
    int n = 5, k = 2;
    int answer = findTheWinner(n,k);

    cout<<answer;

    return 0;
}
