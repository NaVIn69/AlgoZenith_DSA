#include <iostream>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // 
    int head=-1,tail=0;
    
    int len=0;
    int cnt=0;
    int prev=0;
    int ans=0;
    while(tail<n){
        while(head+1<n &&len<k){
            
            ans=ans|a[head+1];
            prev=max(prev,ans);
        len++;
        head++;
        }
        cout<<ans<<" ";
        if(ans%2!=0){
            cnt++;
        }
        if(tail<=head){
          
        ans=ans^a[tail];
           
            len--;
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    cout<<cnt<<endl;
    
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
