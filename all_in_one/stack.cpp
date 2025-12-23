#include<bits/stdc++.h>
using namespace std;

// last in first out (LIFO)
void insertatBottom(int x,stack<int>&st){
    if(st.empty()){
        st.push(x);
        return ;
    }
    int num=st.top();
    st.pop();
    insertatBottom(x,st);
    st.push(num);
}
void reverseStack(stack<int>&st){
    if(st.empty()){
        return ;
    }
    int num=st.top();
    st.pop();
    reverseStack(st);
    insertatBottom(num,st);
}
void sorted_way(stack<int>&st,int x){
    if(st.empty() || st.top()<=x){
        st.push(x);
        return ;
    }
    int num=st.top();
    st.pop();
    sorted_way(st,x);
    st.push(num);

}
void sort_stack(stack<int>&st){
    if(st.empty()){
        return ;
    }
    int num=st.top();
    st.pop();
    sort_stack(st);
    sorted_way(st,num);
}

int arr[400400];
 struct stackUsingArray{
       int nextidx;
      stackUsingArray(int sz){
          
          nextidx=-1;
      } 

      void push(int x){
          nextidx++;
          arr[nextidx]=x;
      }
      int pop(){
        if(nextidx==-1){
            return -1e9;
        }
        int val=arr[nextidx];
        nextidx--;
      }
      bool isempty(){
          if(nextidx==-1){
            return true;
          }
          return false;
      }
      bool size(){
          return nextidx+1;
      }
 }

class stackUsingQueue{
    queue<int>q;
    void push(int x){
        if(q.empty()){
            q.push(x);
            return;
        }
        int sz=q.size();
        q.push(x);
        while(sz--){
            q.push(q.front());
            q.pop();
        }
    
    }

    int pop(){
       if(q.empty()){
        return -1e9;
       }  
       int val=q.front();
       q.pop();
       return val;

    }

}

vector<int>nextGreater(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>ngr(n,n); // here next greater element idx
    for(int i=n-1;i>=0;i--){
         while(!st.empty()&&arr[st.top()]<=arr[i]){
            st.pop();
         }
         if(st.empty()){
            ngr[i]=n;
         }else{
           ngr[i]=st.top();
         }
         st.push(i);
    }
    return ngr;

}

vector<int>nextsmaller(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>nsr(n,n); // here next greater element idx
    for(int i=n-1;i>=0;i--){
         while(!st.empty()&&arr[st.top()]>=arr[i]){
            st.pop();
         }
         if(st.empty()){
            ngr[i]=n;
         }else{
           ngr[i]=st.top();
         }
         st.push(i);
    }
    return nsr;  
} 

vector<int>prevsmaller(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>prevsmaller(n,-1);
    for(int i=0;i<n;i++){
         while(!st.emtpy()&&arr[st.top()]>=arr[i]){
            st.pop();
         }
         if(st.empty()){
            prevsmaller[i]=-1;
         }else{
            prevsmaller[i]=st.top();
         }
         st.push(i);
    }
    return prevsmaller;
}
// here we can find out in how many subarray that element if prev_smaller and next_smaller


// for finding the maximum element in the window size of k -> tc O(n) n<=10^7 -> we can use multiset O(nlogn)n
struct monotone_deque_maxi{
    deque<int>dq;
    void insert(int x){
       while(!dq.empty()&&dq.back()<x){
          dq.pop_back();
       }
       dq.push_back(x);
    }
  // erase
  void erase(int x){
     if(dq.front()==x){
      dq.pop_front();
     }
  }
  
  // for getting the maximum value 
  int getmax(){
    return dq.front();
  }
  
  };

  struct monotone_deque_min{
    deque<int>dq;
    void insert(int x){
        while(!dq.empty()&&dq.back()>x){
            dq.pop_back();
        }
        dq.push_back(x);
    }

    void erase(int x){
        if(dq.front()==x){
            return dq.front();
        }
    }
    int getmin(){
        return dq.front();
    }
  }
// trapping water -> here we have to find out the contribution of each bar , 
// for each bar we have to find out the nextgreater and previousgreater element , upto minimum of both element - height of bar is the contribution

// in the paranthesis , just focus on the closing bracket, how , optimally we can make it balanced with opening bracker

struct node{
  int key,val;
  node*prev,*next,cnt;
     node(int key_,int val_){
        key=key_;
        val=val_;
        cnt=1;
     }

} 

struct LRU{
    node*head,*tail;
    unordered_map<int,node*>mpp;
    int cap_;
    int sz=0;
    LRU(int capacity){
        head=new node(-1,-1);
        tail=new node(-1,-1);
        cap_=capacity;
        head->next=tail;
        tail->prev=head;
        sz=0;
    }

    void addnode(node*currnode){
       // head ke badd
       node*headnext=head->next;
       currnode->next=headnext;
       headnext->prev=currnode;
       head->next=currnode;
       currnode->prev=head;
       mpp[currnode->key]=head->next;
    }
    void deletenode(node*currnode){
       node*delnext=currnode->next;
       node*delprev=currnode->prev;
       delnext->prev=delprev;
       delprev->next=delnext;
    }

    int getval(int key){
       if(mpp.find(key)==mpp.end()){
          return -1; // not found
       }
       node*curr=mpp[key];
       mpp.erase(key);
       int val=curr->val;
       node*newnode=new node(key,val);
       deletenode(curr);
       addnode(newnode);
    //    mpp[key]=head->next;
       return val;

    }
    
    void insert(int key,int val){
          if(mpp.find(key)!=mpp.end()){
              node*curr=mpp[key];
              mpp.erase(key);
              deletenode(curr);
          }  
          if(mpp.size()==cap_){
             // here we delete the node from tail side 
             node*del=tail->prev;
             mpp.erase(del->key);
             deletenode(del);
          }
         node*newnode=new node(key,val);
         addnode(newnode); 
    }

}

struct list{
    node*head,*tail;
    int size;
    list(){
        head=new node(0,0);
        tail=new node(0,0);
        size=0;
        head->next=tail;
        tail->prev=head;
    }

    void addnode(node*newnode){
        size++;
        node*headnext=head->next;
        head->next=newnode;
        newnode->next=headnext;
        newnode->prev=head;
        headnext->prev=newnode;   
    }

    void deletenode(node*delnode){
        node*delnext=delnode->next;
        node*delprev=delnode->prev;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
    }
}

struct LFUCache{
    map<int,node*>keynode;
    map<int,list*>freqlist;
    int maxcachesize,minfreq,currsize;
    LFUCache(int cap){
        maxcachesize=cap;
        currsize=0;
        minfreq=0;
    }

    void updatefreqlist(node*temp){
        // here we have temp;
        int freq=temp->cnt;
        list*List=freqlist[freq];
        List->deletenode(temp);
        if(freq==minfreq&&List->size==0){
            minfreq++;
        }
        List*nexthigherfreqlist=new list();
        if(freqlist.find(freq+1)!=freqlist.end()){
            nexthigherfreqlist=freqlist[freq+1];
        }
        temp->cnt+=1;
        nexthigherfreqlist.addnode(temp);
        freqlist[temp->cnt]=nexthigherfreqlist;
        keynode[temp->key]=temp;

    }
    int get(int key){
      if(keynode.find(key)!=mpp.end()){
           node*curr=keynode[key];
           keynode.erase(key);
           int val=curr->val;
           updatefreqlist(curr);
           return val;
      }
      return -1;
    }
void  put(int key,int val){
          if(keynode.find(key)!=keynode.end()){
              node*curr=keynode[key];
              curr->val=val;
              keynode.erase(key);
              updatefreqlist(curr);

          }else{
            if(maxcachesize==currsize){
                // here we have to remove the element from minfreq
                list*List=freqlist[minfreq];
                List->deletenode(List->tail->prev);
                keynode.erase(List->tail->prev->key);
                currsize--;
            }
            minfreq=1;
            list*listfreq=new list(); 
            if(freqlist.find(minfreq)!=freqlist.end()){
                listfreq=freqlist[minfreq];
            }
            node*newnode=new node(key,val);
            listfreq->addnode(newnode);
            freqlist[minfreq]=listfreq;
            keynode[key]=newnode;
          }
    }
}



void solve(){

}
int main(){
    solve();
}