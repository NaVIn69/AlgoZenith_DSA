#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
              
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
    multiset<int>mt;
    trie(){
      root= new node;
    }
    
    void insert(int n,int ln){
        node*curr=root;
        mt.insert(n);
        for(int i=ln-1;i>=0;i--){
            curr->cnt++;
            int x=(n&(1<<i) ? 1 :0);
            if(curr->child[x]==NULL){
                // here we have to create new node
                curr->child[x]=new node;
            }
            curr=curr->child[x];
        }
        curr->cnt++;
    }
    // here we are query for the x^y<=k
    int query_cnt(int y,int k,int ln){
        int ans=0; // here we count that how many element we have such that x^y<=k
        node*curr=root;
        for(int i=ln-1;i>=0;i--){
            if(y&&(1<<i)){
                // here if the ith bit of y is set
                // here a represent the direction of movement in the trie

                // b represent the ith bit of the y and c represent the ith bit of k

                if(k&(1<<i)){  // a^b<=c here c=1 and b=1 , then on one it give me correct and
                  ans+=(curr->child[1]->cnt); // here we count in the right direction , bcz it give me correct answer
                  curr=curr->child[0];
                }else{ // a^b<=c here c=0 and b=1 , then a must be 1 then we 
                    curr=curr->child[1];

                }
            }else{
                if(k&(1<<i)){ // here a^b<=c here b=0 and c=1 then for it always give me answer
                    ans+=curr->child[0]->cnt;
                    curr=curr->child[1];
                }else{
                    // here we have to go in the right direction , a^b<=c here b=0 and c=0 a must be zero ,
                    curr=curr->child[0 ];
                }


            }
        }
        return ans;
    }
    
    int max_query(int n,int ln){
        node*curr=root;
        int ans=0;
        for(int i=ln-1;i>=0;i--){
            int x=(n&(1<<i)) ? 0: 1;
            // here we have to go into the opposite bit direction
            if(curr->child[x]!=NULL){
                // means we have to traverse in that direction
                ans^=(1<<i);
                curr=curr->child[x];
            }else{
                // here we have to travel in the opposite direction
                curr=curr->child[x^1];
            }
               
        }
        return ans;
    }
    
    void Delete(int y,int ln){
        // here we have to delete that element ,
        auto it=mt.find(y);
        if(it!=mt.end()){
            mt.erase(it);
            auto it1=mt.find(y);
            // here we have to decrease the only it 
            if(it1!=mt.end()){
            node*curr=root;
            for(int i=ln-1;i>=0;i--){
                curr->cnt--;
                int x=(y&(1<<i)) ? 1 :0;
                curr=curr->child[x];
            }
            curr->cnt--;
        }else{

        }
       
    }
    
}

};
void solve(){



}
signed main(){
    solve();
}