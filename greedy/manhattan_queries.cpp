#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int x[n],y[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
    sort(x,x+n);
    sort(y,y+n);
    // finding the manhattan distance
    int prefix_x[n],prefix_y[n];
    for(int i=0;i<n;i++){
        prefix_x[i]=x[i];
        prefix_y[i]=y[i];
        if(i){
            prefix_x[i]+=prefix_x[i-1];
            prefix_y[i]+=prefix_y[i-1];
        }
    }
    int query;
    cin>>query;
    while(query--){
        int x1,y1;
        cin>>x1>>y1;
        int index_x=upper_bound(x,x+n,x1)-x;
        int manhattan_dis_x=0; 
        if(index_x!=n && index_x!=0){
         manhattan_dis_x=index_x*x1-prefix_x[index_x-1]+(prefix_x[n-1]-prefix_x[index_x-1])-(n-index_x)*x1;
        }else{
             manhattan_dis_x=abs(x1*n-prefix_x[n-1]);
        }

        int index_y=upper_bound(y,y+n,y1)-y;
        int manhattan_dis_y=0;
        if(index_y!=n && index_y!=0){
         manhattan_dis_y=index_y*y1-prefix_y[index_y-1]+(prefix_y[n-1]-prefix_y[index_y-1])-(n-index_y)*y1;
        }else{
             manhattan_dis_y=abs(y1*n-prefix_y[n-1]);
        }
        cout<<(manhattan_dis_x+manhattan_dis_y)<<endl;
    }

    

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}