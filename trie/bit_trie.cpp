#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
// here we struct the node and which array of 2 size which store 0th and 1th child
struct node{
    node*child[2];
    int cnt=0;
    // here we count ,how many number is present the trie
    node(){
        child[0]=NULL;
        child[1]=NULL;
    }
};

struct trie{
    node*root;
    trie(){
        root=new node;
    }
// here we have to insert the value n in the trie and try to update the tree
// ln -> ln is the bit length , means 
    void insert(int n,int ln){
        node*curr=root;
        // here we traversing from the msb means 
        // means levelwise , we are traversing , on that node
        for(int i=ln-1;i>=0;i--){
           curr->cnt++;
           // here we are updating the count of every node where we are going through bit value of n , 
           int x=(n&(1<<i)) ? 1: 0; // here we have been check the ith bit of the number n 
           if(curr->child[x]==NULL){
            // here we have to create the new node , because 
             curr->child[x]=new node;

           }
             // here we are moving in that direction
             curr=curr->child[x];  
        }
        curr->cnt++;

      }
      void Delete(int n,int ln){
        node*curr=root;
        // here root node has two child // either 0 or 1
        for(int i=ln-1;i>=0;i--){
            curr->cnt--;
            int x=(n&(1<<i)) ? 1: 0;
            curr=curr->child[x];
        }
        curr->cnt--;
      }
      int max_query(int n,int ln){
        node*curr=root;
        int ans=0;
        for(int i=ln-1;i>=0;i--){
           int x=(n&(1<<i)) ? 1 : 0;
           // for getting maximum xor value , we have to go in the opposite bit of x 
           // then xor value give me maximum value ,
           // let if that node is dont exit which give me maximum xor value , we have been force to go on the other side
           if(curr->child[x^1]!=NULL){ // prefer opposite bit 
             ans|=(1<<i);
             // here we are setting the ith bit of ans number
             curr=curr->child[x^1]; 
           }else{
            // opposite bit is missing then we have to go in the same bit (forced)
            curr=curr->child[x];
           }
           
        } 
        return ans;  
    
      }
};

void solve(){
    cin>>n;
    trie*newnode= new trie();
    // cout<<"location of trie  "<<x<<endl;
    // cout<<"location of root of that trie  "<<x->root<<endl;
    // cout<<" before inserting location of root child "<<x->root->child[0]<<" "<<x->root->child[1]<<endl;
    // x->insert(5,3);
    // x->insert(7,3);
    // x->insert(3,3);
    // cout<<" after inserting location of root child "<<x->root->child[0]<<" "<<x->root->child[1]<<endl;
    // cout<<x->root->cnt<<endl; // it represent the how many element we have inserted
    // x->Delete(5,3);
    // cout<<x->root->cnt<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];   
        
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"mnav"<<endl;
    newnode->insert(arr[0],3);
    int maxi=0;
    for(int i=1;i<n;i++){
      
        maxi=max(maxi,newnode->max_query(arr[i],3));
        cout<<maxi<<endl;
        newnode->insert(arr[i],3);
        cout<<newnode->root->cnt<<" ";
    }


}
signed main(){
    solve();
}