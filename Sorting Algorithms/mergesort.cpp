#include<bits/stdc++.h>
using namespace std;
//arrays are always passed by reference - REMEMBER


void mergearrays(int a[],int s,int e){
    int mid = (s+e)/2;

    int i = s;
    int j = mid+1;
    int k = s;

    int temp[100];

    while(i<=mid && j<=e){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++]  = a[j++];
    }

    //We need to copy all element to original arrays
    for(int i=s;i<=e;i++){
        a[i] = temp[i];
    }


}

void mergeSort(int a[],int s,int e){
    //Base case - 1 or 0 elements
    if(s>=e){
        return;
    }

    //Follow 3 steps
    //1. Divide
    int mid = (s+e)/2;

    //Recursively the arrays -> s,mid and mid+1,e
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);

    //Merge the two parts
    mergearrays(a,s,e);

}


int main(){
  int a[] = {7,3,10,5,6,2,-5};
  mergeSort(a,0,6);

  for(int i=0;i<7;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}

