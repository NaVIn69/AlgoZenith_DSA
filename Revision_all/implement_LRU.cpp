#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct node{
    int key_,val_;
    node*prev,*next;
    
    node(int key,int val){
        key_=key;
        val_=val;
    }
};

// here we need two thing first doubly linkedlist and map
struct LRUcache{
    node*head,*tail;
    unordered_map<int,node*>mpp; // this map store the key and where we have been store that key into the list 
    int cap_;
    LRUcache(int capacity){
     cap_=capacity;
     head=new node(-1,-1);
     tail=new node(-1,-1);
     head->next=tail;
     tail->prev=head;
     head->prev=NULL;
     tail->next=NULL;
    }

    void add(node*newnode){
        // we have to add the node right after the head
        node*old_next=head->next;
        head->next=newnode;
        newnode->prev=head;
        old_next->prev=newnode;
    }

    void Deletenode(node*newnode){
       node*old_prev=newnode->prev;
        node*old_next=newnode->next;
        old_next->prev=old_prev;
        old_prev->next=old_next;
    }

    int get(int key){
        if(mpp.find(key)!=mpp.end()){
            node*existing_node=mpp[key];
            Deletenode(existing_node);
            add(existing_node);
            mpp.erase(key);
            mpp[key]=head->next;
            return existing_node->val_;

        }else{
            return -1;
        }

    }

    void put(int key,int val){
          // first we have to check is this present in our list or nor
          // it the capacity is full then we have to delete the least Reacent used 
          node*curr=new node(key,val);
          if(mpp.find(key)!=mpp.end()){
              node*exitings=mpp[key];
              mpp.erase(key);
              Deletenode(exitings);
          }
          if(mpp.size()==cap_){
             // capacity is full we have to delete the node from tail side
             node*del=tail->prev;
             mpp.erase(del);
             Deletenode(del);
          }
          mpp[key]=curr;
          add(curr);
    }

};


void solve(){
   
}
signed main(){
    solve();
}