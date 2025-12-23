/*
You are given a string 
S of length 
2N consisting of the characters ( and ). Let S i denote the i-th character from the left of S.
You can perform the following two types of operations zero or more times in any order:

Choose a pair of integers 
(i,j) such that 
1≤i<j≤2N. Swap 
S i and S j. The cost of this operation is A.

Choose an integer 
i such that 
1≤i≤2N. Replace 
S i with ( or ). The cost of this operation is B.

Your goal is to make 
S a correct parenthesis sequence. Find the minimum total cost required to achieve this goal. It can be proved that the goal can always be achieved with a finite number of operations.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    n=n*2;
   
    // here first find the number of open and close bracket which is not correct parenthesis 
    // using depth approach
    int open=0;
    int close=0;
    int depth=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('&& depth<0){
            close=max(close,abs(depth));
            depth=0;
        }
        if(s[i]=='('){
            depth++;
        }else{
            depth--;
        }
    }
    if(depth>0){
        open+=abs(depth);
    }else if(depth<0){
        close+=abs(depth);
    }
    
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}