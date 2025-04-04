#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have to do the search recomendation 
// find the lexicographically smallest top K result for prefix match of s;
int n,q;
struct node{
    node*child[26];
    int prefix; // this store how many string has that node as prefix;
    vector<string>wend;
    node(){
        prefix=0;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
struct string_trie{
   node*root;
   string_trie(){
    root=new node;
   }

   void insert(string s){
    node*curr=root;
    for(int i=0;i<s.size();i++){
        curr->prefix++;
        int x=s[i]-'a';
        if(curr->child[x]==NULL){
            curr->child[x]=new node;
        }
        curr=curr->child[x];
    }
    curr->wend.push_back(s);
   }

   void Delete(string s){
    node*curr=root;
    for(int i=0;i<s.size();i++){
        curr->prefix--;
        int x=s[i]-'a';
        curr=curr->child[x];
    }
    curr->wend.pop_back();
   
}

// here we have given string we have to find that node in trie
 node* Prefix_string(string s){
   node*curr=root;
   for(int i=0;i<s.size();i++){
        int x=s[i]-'a';
        curr=curr->child[x];
     }
     return curr;
 }

// here we are printing the string 
// here we do dfs and printing only the k string
 void dfs(node*temp,int&k){
    
    if(k!=0&&temp->wend.size()!=0){
        cout<<temp->wend[0]<<" ";
        k=k-1;
        if(k==0) return ;
    }
    for(int i=0;i<26;i++){
        if(temp->child[i]!=NULL){

            dfs(temp->child[i],k);
        }
    }
 }


};
void solve(){

    cin>>n;
    // here vector of string // from here we have to make the 
    string_trie*t=new string_trie();
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        t->insert(str);
    }
    cin>>q;
  // here we have to find the topk string which has string s as the prefix 
    while(q--){
        string s;
        int k;
        cin>>s>>k;
        node*temp=t->Prefix_string(s);
        t->dfs(temp,k);
    }

}
signed main(){
    solve();
}