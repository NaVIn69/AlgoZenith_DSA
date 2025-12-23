#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
        int n,m;
	    cin>>n>>m;
	    int arr[n],brr[m];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	       for(int i=0;i<m;i++){
	        cin>>brr[i];
	    }
	   if(n<4||m<4 ||(n+m)<11){
	       cout<<"-1"<<endl;
	       return;
	   }
	    sort(arr,arr+n);
	    sort(brr,brr+m);
	    
	}


signed main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
        solve();
    }

}
