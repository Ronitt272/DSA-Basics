#include<bits/stdc++.h>
using namespace std;

int key(int a[], int s, int e)
{
    int pivot = a[e];
    int k = s;

    for(int i=s;i<=e-1;i++)
    {
        if(a[i]<pivot)
        {
            swap(a[k],a[i]);
            k++;
        }
    }

    swap(a[k],a[e]);
    return k;
}

void quickSort(int a[], int s, int e)
{
    if(s>=e)
    {
        return; //as the array is already sorted.
    }

    int p;
    p = key(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);

}

int main()
{
    int a[] = {7,6,4,3,2,1,0,-6};
    int s=0;
    int e=7;

    quickSort(a,s,e);

    cout<<"The Sorted Array is: ";

    for(int i=s;i<=e;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
