#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n,m;
    cin>>n>>m;
    int text[n],pattern[m];
    for(int i=0;i<n;i++){
        cin>>text[i];
    }
    for(int i=0;i<m;i++){
        cin>>pattern[i];
    }
    vector<int>freq(100100,0);
    for(auto x:pattern){
        freq[x]++;
    }


    // include i
    // exclude i-m
    // check mismatch









    int mismatch=0;
    // here frequency tells me about the number of non_zero frequecy element of pattern array
    for(int i=0;i<100100;i++){
        if(freq[i]!=0) mismatch++;
    }
    for(int i=0;i<n;i++){
        // freq[text[i]]==0 means ye mere pattern wale array me nhi hai
        if(freq[text[i]]==0) mismatch++;
        freq[text[i]]--;
        // freq[text[i]]==0 means sare occurence(in pattern ) mil gaya uss text array ke window me
        if(freq[text[i]]==0) mismatch--;
        // i-m == 0 hoga when we have crossed m element 
        if(i-m>=0){
            // i-m th index element ko leave krne wale hai isliye then we have to check ki ye mere pattern array me lie krta hai yha nhi
            if(freq[text[i-m]]==0) mismatch++;
            freq[text[i-m]]++;
            if(freq[text[i-m]]==0) mismatch--;

        }
        if(mismatch==0){
            cout<<i-m+1<<endl;
        }

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