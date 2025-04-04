#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];

// here we can manipulate the node as  i want , and we can change the answer accordinly
struct node{
   node*child[2];
   int cnt;
   node(){
    child[0]=NULL;
    child[1]=NULL;
    cnt=0;
   }
};

struct trie{
   node*root;
   trie(){
    root=new node;
   }

   void insert(int n,int ln){
    node*curr=root;
    for(int i=ln-1;i>=0;i--){
        curr->cnt++;
       int x=(n&(1<<i)) ? 1 :0;
       // checking ith bit of the n
       if(curr->child[x]==NULL){
        // here we made the path in that direction either o side or 1 side
         curr->child[x]=new node;
       }
       curr=curr->child[x];
    }
    curr->cnt++;

 }

 int max_query(int n,int ln){
    node*curr=root;
    int ans=0;
    for(int i=ln-1;i>=0;i--){
       int x=(n&(1<<i)) ? 1 : 0;
       // for getting maximum xor value , we have to go in the opposite bit of x 
       // then xor value give me maximum value ,
       // let if that node is dont exit which give me maximum xor value , we have been force to go on the other side
       if(curr->child[x]!=NULL){
         ans^=(1<<i);
         // here we are setting the ith bit of ans number
         curr=curr->child[x]; 
       }else{
        // means that node doesnt exit // then we dont set that bit
        curr=curr->child[x];
       }
       
    } 
    return ans;  

  }

};

void solve(){
    cin>>n;
    trie*newnode=new trie();
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];   
        
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"mnav"<<endl;
    newnode->insert(arr[0],3);
    for(int i=1;i<n;i++){
      
        maxi=max(maxi,newnode->max_query(arr[i],3));
        cout<<maxi<<endl;
        newnode->insert(arr[i],5);
        cout<<newnode->root->cnt<<" ";
    }
   
    
  
   // here we create the new node
   // let assume that we have built the trie upto ith index of array and now we finding the that pair which give me
   // maximum xor with a[i+1]the index of the array and we find the number // in the leaf node we have to store that number
   // ln is the bit length 

  


}
signed main(){
    solve();
}