#include <bits/stdc++.h>
using namespace std;
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
	   if(n<4||m<4||(n+m)<11){
	       cout<<"-1"<<endl;
	       return;
	   }
	    sort(arr,arr+n);
	    sort(brr,brr+m);
	    int total=0;
        int i=0;
        int j=0;
	    for( i=n-1;i>=n-4;i--){
	        total+=arr[i];
	        
	    }
	    for( j=m-1;j>=m-4;j--){
	        total+=brr[j];
	    }
       
        vector<int>v;

            for(int l=n-5;l>=0&&(l>=n-7);l--){
                  v.push_back(arr[l]);
            }

      
            for(int k=m-5;k>=0&&(k>=m-7);k--){
                  v.push_back(brr[k]);
            }
     

        
	  sort(v.begin(),v.end());
      int k=v.size();
      for(int m=k-1;m>=0&&m>=k-3;m--){
        total+=v[m];
      }

	    
	    cout<<total<<endl;
	}


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
        solve();
    }

}

