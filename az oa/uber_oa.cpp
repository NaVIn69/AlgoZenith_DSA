#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
#define mp make_pair
int mod=1e9+7;

// here this function give me the input of array
int randBetween2() {
  const int minValue = -200;
  const int maxValue = 200;

  // The keyword static is required now so that the PRNG and distribution
  // are not re-instantiated every time the function is called. This is
  // important for them both to work as intended. Re-instantiating resets
  // their state, and they constantly start from scratch. They must be allowed
  // to persist their state for better results.
  static std::mt19937 prng(std::random_device{}());  // Note the static
  static std::uniform_int_distribution<int> dist(minValue, maxValue);

  return dist(prng);
}
void solve(){  
    int arr[4];
    // in array we have been store the speed,alph,beta,delta
    int maxi=INT_MIN;
    int ans=0;
    int mini=INT_MAX;
    for(int i=0;i<4;i++){
        arr[i]=randBetween2();
        cout<<arr[i]<<" ";
        maxi=max(maxi,abs(arr[i]));
      if(maxi==arr[i]){
        maxi=arr[i];
      }else{
        mini=min(arr[i],mini);
      }
    }
    cout<<endl;
    if(abs(mini)==maxi){
        //this is possible when d*t<0 means neither d become less than 0 and neither time become less than 0
        cout<<"-1"<<" "<<"-1"<<endl;
        return ;
    }

    sort(arr,arr+4);
    // arr[0]<0 means 
    if(arr[0]<0){
        // here after sorting the 
         int t=(arr[0]+arr[2])/2;
         int d=arr[3]/t;
         cout<<d<<" "<<t<<endl; 
    }else{
        int t=(arr[1]+arr[2])/2;
        int d=arr[3]/t;
        cout<<d<<" "<<t<<endl;

    }

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

}