#include<bits/stdc++.h>
using namespace std;
class  stackusingarray{
   int*data;
   int nextindex;
   int capacity;
   public:
   //static stack
   stackusingarray(int totalsize){
    data=new int[totalsize];
    nextindex=0;
    capacity=totalsize;
   }
   int size(){
    return nextindex;
   }
   bool isempty(){
    return nextindex==0;
   }
   void push(int element){
    if(nextindex==capacity){
        // cout<<"stack is full"<<endl;
        // return ;
     int*newdata=new int[2*capacity];
     for(int i=0;i<nextindex;i++){
         newdata[i]=data[i];
     }
     capacity*=2;
     delete data;
     data=newdata;
    }
    
    data[nextindex++]=element;
   }
   int pop(){
    if(isempty()) {cout<<"satck is empty"<<endl; return INT32_MIN;}
    int ans=data[nextindex-1];
    nextindex--;
    return ans;
   }
  int top(){
    if(isempty()) {cout<<"stack is empty"<<endl; return INT16_MAX;}
    return data[nextindex-1];
  }

};
int main(){
    stackusingarray s1(5);
    s1.push(20);
    s1.push(30);
    s1.push(-2);
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;
    s1.push(50);
    s1.push(60);
    s1.push(70);
    s1.push(80);
    s1.push(90);
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.top()<<endl;


}