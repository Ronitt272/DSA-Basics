#include <iostream>
#include<cstring>
using namespace std;

int main() {
	// your code goes here
	int a[10],n;
	cin>>n;

	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j])
                swap(a[i],a[j]);

    cout<<"sorted array: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
