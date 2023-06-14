#include<iostream>
using namespace std;

template<typename T>

class Stack{
   T *arr;
   int nextIndex;
   int capacity;

   public:
       Stack(){
          capacity = 4;
          arr = new T[capacity];
          nextIndex = 0;
       }
       Stack(int cap){
         capacity = cap;
         arr = new T[capacity];
         nextIndex = 0;
       }
       /// return no of elements present in stack
       int size(){
          return nextIndex;
       }
       bool isEmpty(){
         /*if(nextIndex==0){
            return true;
         }else{
            return false;
         }*/
         return nextIndex==0;
       }

       void push(T ele){  //for dynamic stacks
          if(nextIndex==capacity){
            int *newArr = new T[2*capacity];
            for(int i=0;i<capacity;i++){
                newArr[i] = arr[i];
            }
            delete []arr;
            arr = newArr;
            capacity = 2*capacity;
          }
          arr[nextIndex] = ele;
          nextIndex++;
       }

       void pop(){
          if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return;
          }
          nextIndex--;
       }
       T top(){
         if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return 0;  //0 can mean NULL for a pointer. It can be used for all the data types and that is why this change is made.
          }  //to visualize, think that if T is a pointer, 0 can mean NULL
         return arr[nextIndex-1];
       }
};

int main(){
  Stack<int> s(4);
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  cout<<s.top()<<endl;
  s.pop();

  cout<<s.top()<<endl;
  s.pop();

  cout<<s.top()<<endl;
  s.pop();

  cout<<s.size()<<endl;
  cout<<s.isEmpty()<<endl;

  Stack<int> s2(10);
  for(int i=1;i<=10;i++){
    s2.push(i);
  }
  /// print content of stack
  while(!s2.isEmpty()){
    cout<<s2.top()<<endl;
    s2.pop();
  }
  cout<<s2.size()<<endl;
  return 0;
}
