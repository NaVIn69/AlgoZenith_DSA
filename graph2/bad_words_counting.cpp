#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<string>badwords;
vector<vector<string>>sentence;
struct node{
    node*child[26];
    int prefix;
    vector<string>wend;
    node(){
        prefix=0;
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
 bool searchword(string s){
     node*curr=root;
    for(int i=0;i<s.size();i++){
        curr->prefix++;
         int x=s[i]-'a';
         if(curr->child[x]==NULL){
            return false;
         }
         curr=curr->child[x];
    }
    return true;
 }



};
void solve(){
    int n,m;
    cin>>n>>m;
    // n= size of sentence array
    // m= size of bad words array
    badwords.resize(m);
    sentence.resize(n);
    trie*t=new trie();
    for(int i=0;i<m;i++){
        cin>>badwords[i];
        t->insert(badwords[i]);
    }
    for(int i=0;i<n;i++){
       int k;
       // sentence size
       cin>>k;
       vector<string>temp;
       for(int j=0;j<k;j++){
        string str;
        cin>>str;
          temp.push_back(str);
       }
       sentence[i]=temp;

       
    }
    // for(int i=0;i<n;i++){
      
   
    //    for(int j=0;j<sentence[i].size();j++){
    //         cout<<sentence[i][j]<<" ";
    //    }
    //    cout<<endl;

       
    // }

    vector<pair<int,vector<string>>>ans;

    
    for(int i=0;i<n;i++){
        for(int j=0;j<sentence[i].size();j++){
        string str=sentence[i][j];
        string temp="";
        int cnt=0;
        for(int j=0;str[j]!='\0';j++){
            if(str[j]!=' '){
                temp+=str[j];
            }else{
                // when we find the words then we have to check that word is bad word or not
             if( t->searchword(temp)) cnt++;
             temp="";

            }
        }
        ans.push_back({cnt,sentence[i]});
        }
    }
    sort(ans.rbegin(),ans.rend());
    // more bad words wale first pe ayega
    for(int i=0;i<ans.size();i++){
        
    }
    // cout<<endl;
    






}
signed main(){
    solve();

}