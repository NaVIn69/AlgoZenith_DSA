#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here 26 size binary string tells me about which character is good or bad
// and we have given the string , here we have find the total number of good distnict substring in which we have k badones
 string str,bs;
 int k;
 struct node{
    node*child[26];
    node(){
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
    
 };
void solve(){
    cin>>str;
    cin>>bs;
    cin>>k;
    



}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}