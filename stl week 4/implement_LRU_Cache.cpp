#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct node{
    int key_;
    int val_;
    node*prev,*next;
    node(int key,int val){
        key_=key;
        val_=val;
    }

};
struct LRUcache{
      node*head,*tail;
      unordered_map<int,node*>mpp;
      int cap_;
      LRUcache(int capacity){
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
        cap_=capacity;
      }

      void add(node*newnode){
        // here add the node right after the head , and we have to put that node and their address into the map
        node*old_next=head->next;
        newnode->prev=head;
        newnode->next=old_next;
        head->next=newnode;
         old_next->prev=newnode;
         mpp[newnode->key_]=newnode;
      

      }
      void deletenode(node*delnode){
         // here we delete the node from the end // like tail se phale we delete the node
         node * delprev = delnode -> prev;
         node * delnext = delnode -> next;
         delprev -> next = delnext;
         delnext -> prev = delprev;

      }
      int get(int key){
        // here we have to get the value of that key 
        if(mpp.find(key)!=mpp.end()){
            node*curr=mpp[key];
            // here we have to add that node and also we have to delete that node from where that node is present rightnoe
            int val=curr->val_;
            mpp.erase(key);
            deletenode(curr);
            add(curr);
            // here we are storing in the map with <key, node_address>
            mpp[key]=head->next;
            return val;

        }
        return -1;
      }
      void put(int key,int value){
        // here first we have to find the map
        if(mpp.find(key)!=mpp.end()){
            node*existing=mpp[key];
            mpp.erase(key);
            deletenode(existing);
        }
        // capacity ke equal ho gaya then we have to delete the element from the tail side 
        if(mpp.size()==cap_){
            // here we have to delete from tail side
            mpp.erase(tail->prev->key_);
            deletenode(tail->prev);

        }
        // 
        node*temp=new node(key,value);
        add(temp);
        mpp[key]=temp;


      }


}

void solve(){

}
signed main(){

    solve();

}