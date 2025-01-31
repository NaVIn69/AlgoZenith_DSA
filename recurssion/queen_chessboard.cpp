#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int matrix[10][10];
int queens[8];
int n=8;

bool check(int row,int col){
    if(matrix[row][col]==100) return 0;
    for(int pr=0;pr<row;pr++){
        int pc=queens[pr];
        if(pc==col||abs(pr-row)==abs(pc-col)){
            return 0;
        }
    }
    return 1;
}
int rec(int level){
    if(level==8){
        return 1;
    }

    int ans=0;
    for(int ch=0;ch<n;ch++){
        if(check(level,ch)){
            queens[level]=ch;
            ans+=rec(level+1);
            queens[level]=-1;
        }
    }
    return ans;
}
void solve(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            char ch;
            cin>>ch;
            if(ch=='.'){
                matrix[i][j]=-1;
            }else{
                matrix[i][j]=100;
            }
        }
    }
    cout<<rec(0)<<endl;


}
signed main(){
    solve();
}