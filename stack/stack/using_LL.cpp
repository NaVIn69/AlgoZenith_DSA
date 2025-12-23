#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*next;
    int data;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
class stack1{
    Node*head;
    int size;
    public:
     stack1(){
     head=NULL;
     size=0;
    }
    int top(){
        return head->data;
    }
    void push(int element){
        Node*newnode=new Node(element);
        if(head==NULL){
            head=newnode;
        }else{
            newnode->next=head;
            head=newnode;
        }
    }
    int pop(){
        int ans=head->data;
        Node*temp=head;
        head=head->next;
        delete temp;
        return ans;
    }
    bool isempty(){
        return head==NULL;
    }


};
int main(){
    stack1 s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    cout<<s.top()<<endl;


}