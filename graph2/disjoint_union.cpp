#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct Dsu{
    int n;
    vector<int>parent,rank,size;
    Dsu(){}
    Dsu(int a){
      n=a;
      parent.resize(n+1);
      rank.resize(n+1);
      size.resize(n+1);
      for(int i=0;i<=n;i++){
        parent[i]=i;
        rank[i]=0;// rank is telling me the height of that tree
        size[i]=1;// size telling me the size of that subtree
      }
    }
    int findUpar(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=findUpar(parent[x]);
    }

    void mergeBysize(int x,int y){
        int xroot=findUpar(x);
        int yroot=findUpar(y);
        if(xroot!=yroot){
            if(size[xroot]>=size[yroot]){
                // here x becomes the parent of y
                parent[yroot]=xroot;
                size[xroot]+=size[yroot];
            }else{
                // here y becomes the parent of x
                 parent[xroot]=yroot;
                size[yroot]+=size[xroot];
            }
        }
    }
    // merge by rank is like the merging two tree about their heights 
    
    void mergeByrank(int x,int y){
         int xroot=findUpar(x);
        int yroot=findUpar(y);
        if(xroot!=yroot){
            if(rank[xroot]>rank[yroot]){
                 // x become the parent of y
                 parent[yroot]=xroot;

            }else if(rank[yroot]>rank[xroot]){
                parent[xroot]=yroot;
            }else{
                // here y become the parent 
                // and increasin the height of tree by 1
                parent[xroot]=yroot;
                rank[yroot]++;
            }
        }
    }
};
void solve(){
    int n,q;
    cin>>n>>q;
    Dsu ds(n);
    while(q--){
       int ch;
       cin>>ch;
       if(ch==0){
        // merging the node
        int x,y;
        cin>>x>>y;
        ds.mergeBysize(x,y);
       }else{
        // here we have to find they are in same component or not
        int x,y;
        cin>>x>>y;
        int parU_X=ds.findUpar(x);
        int parU_y=ds.findUpar(y);
        if(parU_X==parU_y){
            cout<<"1"<<endl;
        }else{
            cout<<"0"<<endl;
        }


       }
    }

}
signed main(){
    solve();
}