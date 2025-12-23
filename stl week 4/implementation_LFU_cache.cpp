#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node{
    int key,val,cnt;
    node*prev,*next;
    node(int key_,int val_){
     key=key_;
     val=val_;
     cnt=1; // this node tell me in which freqlist map i am at
    }

};
// in every freq has the list which head tail and size tells us about how many element is present in the list
struct List{
    int size;
    node*head,*tail;
    List(){
        head=new node(0,0);
        tail=new node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addnode(node*newnode){
        // here we add the node right after that newnode
        node*old_next=head->next;
        newnode->next=old_next;
        newnode->prev=head;
        old_next->prev=newnode;
        head->next=newnode;
        size++;
    }
    void removenode(node*delnode){
         node*del_next=delnode->next;
         node*del_prev=delnode->prev;
         del_next->prev=del_prev;
         del_prev->next=del_next;
         size--; // removing the node from list
    }
};
 class LFUCache{
    map<int,node*>keynode; // for every key we have been store the address of that node
    map<int,List*>freq_list; // for every frequency we have been store the list which has head tail , size addnode() , removenode()
    int maxSizecache,minfreq,currsize;
    LFUCache(int capacity){
        maxSizecache=capacity;
        minfreq=0;
        currsize=0;
    }

    void updatefreqlistmap(node*temp){
        keynode.erase(temp->key);
        // here we have to remove from previous freqlistmap
        freq_list[temp->cnt]->removenode(temp); // here we are removing the node from that freqlist
        // here we are checking that list after removind , if that list is minfreqlist and their listsize ==0 after removal , then we update the 
        // min freq list
        if(temp->cnt==minfreq&&freq_list[temp->cnt]->size==0){
            minfreq++;
        }

        List*nexthigherfreqlist=new List(); // here we are making the nexthigherfreqlist 
        
        if(freq_list.find(temp->cnt+1)!=freq_list.end()){
            // here we have been checking the next higher freq in freq_list 
            // if present then we have to add that node in that freqlist
            // if not then we have add new list
            nexthigherfreqlist=freq_list[temp->cnt+1]; // assign the list to that
        }
        temp->cnt+=1;
        nexthigherfreqlist->addnode(temp);
        freq_list[temp->cnt]=nexthigherfreqlist;
        keynode[temp->key]=temp;

    }

    int get(int key){
        if(keynode.find(key)!=keynode.end()){
            node*curr=keynode[key]; // here we geting that key then we have update the frequency of that key 
            int val=curr->val; 
            keynode.erase(key);
            updatefreqlistmap(curr);
            return val;
        }
        return -1;
    }
    void put(int key,int value){
         if(keynode.find(key)!=keynode.end()){
            node*curr=keynode[key];
            curr->val=value;
            updatefreqlistmap(curr);
         }else{
            // here we have to put tha {key, value} 
            if(currsize==maxSizecache){
                // here we have to insize the minfreq list and here we have to delete the least recently used element
                List*list=freq_list[minfreq];
                keynode.erase(list->tail->prev->key);
                list->removenode(list->tail->prev);
                // here we are removig one element then currsize is going to decrease
                currsize--;
            }
            currsize++;
            minfreq=1;
            List*listfreq=new List(); 
            if(freq_list.find(minfreq)!=freq_list.end()){
                listfreq=freq_list[minfreq];
            }
            node*newnode=new node(key,value);
            listfreq->addnode(newnode);
            keynode[key]=newnode;
            freq_list[minfreq]=listfreq;

         }
    };
      
};

signed main(){

}