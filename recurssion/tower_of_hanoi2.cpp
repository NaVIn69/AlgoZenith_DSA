#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

}
void tower_hanoi(int x,int source,int target,int aux){
    if(x==0) return;
    tower_hanoi(x-1,source,aux,target);
    cout<<"MOve disc"<<x<<"from"<<source<<"to"<<target<<endl;
    tower_hanoi(x-1,aux,target,source);
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    cin>>x;
    tower_hanoi( x,1,3,2);
}