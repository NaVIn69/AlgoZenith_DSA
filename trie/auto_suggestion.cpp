#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,maxlen,q;
vector<string>v;

struct node{
    node*child[26];
    int prefix;
    multiset<string>wend;// how many string end on that node
    node(){
        prefix=0;
        wend.clear();
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }

};
struct trie{
    node*root;
    trie(){
        root=new node;
    }

    void insert(string s){
        // here we are inserting the string s // 
        node*curr=root;
        // here we are travelling on the string and try to append each character of string into the trie;
        string str="";
        for(int i=0;i<s.size();i++){
         
            curr->prefix++;
              int x=s[i]-'a' ;
              if(curr->child[x]==NULL){
                  curr->child[x]=new node;
              } 
              curr=curr->child[x];
              curr->wend.insert(s);
        }
        // curr->wend.push_back(s);
    }

    void query(string s, int k){
        node *curr = root;
        // on every iteration we have to find the 
        for (int i = 0; i < s.length(); i++){
             char ch=s[i];
             if(curr->child[ch-'a']==NULL){
                // means we dont have (i.....s.size()) part of string into my trie
                while(i<s.size()){
                   cout<<endl;
                   i++;
                   // for every character we have to print endl
                }
                continue;
             }
             curr=curr->child[ch-'a'] ;// we are on that node which s[0.....i] string as prefix , from now we have to print 
             // the topk lexicographically where s[0.....i] as prefix
             if(curr->wend.size()>0){
                auto it=curr->wend.begin();
             for(int i=0;i<k;i++){
                if(it!=curr->wend.end()){
                    cout<<*it<<" ";
                    it++;
                }else{
                    break;
                }
             }
             // here we have been printed the topk string 
             cout<<endl;
            }
        
    
            // upto ith character of string s ,we have reach at that node which has prefix of s[0...i] now all the string 
            // below that has prefix of s[0....i] now ,here we have to print topk lexicographically string

           
    }
}

   

  


};
void solve(){
  cin>>n>>maxlen>>q;
  trie*newnode=new trie();
  for(int i=0;i<n;i++){
    int len;
    cin>>len;
    string str;
    cin>>str;

    newnode->insert(str);
  }


    while(q--){
        int m;
        cin>>m;
        string s;
        cin>>s;
        int k;
        cin>>k;
        newnode->query(s,k);


    }
   



}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}