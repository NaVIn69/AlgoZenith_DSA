#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
vector<string>all_sol;
string curr="";
map<char,int>mpp;
bool isbalanced(string s,int k){
    int depth=0;
    int maxi=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='('){
            depth++;
            maxi=max(depth,maxi);
            if(depth>k) return 0;

        }else{
            depth--;
        }
        if(depth<0){
            return 0;
        }
    }
    return depth==0&&maxi>=k;
}
void rec(int level){
    //base case
    if(level==n){

        if(isbalanced(curr,k)){
        all_sol.push_back(curr);
        }
        return;
    }
    //recursive call
    for(auto v:mpp){
        if(v.second!=0){
            //place
            mpp[v.first]--;
            curr+=v.first;
            //move to the next level;
            rec(level+1);
            //unplace
            mpp[v.first]++;
            curr.pop_back();

        }
    }

}
void solve(){
    cin>>n>>k;
    mpp['(']=n/2;
    mpp[')']=n/2;
    rec(0);
    for(int i=0;i<all_sol.size();i++){
        string str=all_sol[i];
        cout<<str<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}