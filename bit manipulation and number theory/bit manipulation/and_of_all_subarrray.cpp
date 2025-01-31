// all and value of all subarrray
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
          cin>>arr[i];
    }
    map<int,int>prev_ends;
    map<int,int>all_and_freq;
    //here in that map we are storing the all the and value of subarray
    for(int i=n-1;i>=0;i--){
        map<int,int>new_ends;
        for(auto v:prev_ends){
            new_ends[v.first&arr[i]]=max(new_ends[v.first&arr[i]],v.second);
        }
        new_ends[arr[i]]=max(new_ends[arr[i]],i);
        prev_ends=new_ends;
        vector<pair<int,int>>v(new_ends.begin(),new_ends.end());
        reverse(v.begin(),v.end());
        cout<<"starting at index "<<" "<<i<<endl;
        for(int en=0;en<v.size();en++){
            if(en==0){
            cout<<i<<" "<<v[en].second<<" "<<v[en].first<<endl;
            all_and_freq[v[en].first]+=v[en].second-i+1;
            }else{
                //the subarray starting with i and ending with any index between v[en-1].second+1 and v[en].second ke bich sare value give me v[en].first
                cout<<v[en-1].second+1<<" "<<v[en].second<<" "<<v[en].first<<endl;
                all_and_freq[v[en].first]+=v[en].second-v[en-1].second+1;
            }
             
        }

    }
    cout<<all_and_freq[k]<<endl;

  


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}