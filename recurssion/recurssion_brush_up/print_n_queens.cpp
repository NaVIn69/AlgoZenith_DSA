#include<bits/stdc++.h>
using namespace std;

vector<vector<string>>final_ans;
  int n;
  vector<int>queens;
  bool check(int row,int col){
     for(int pr=0;pr<row;pr++){
        int pc=queens[pr];
        if(pc==col||abs(pr-row)==abs(pc-col)){
            return 0;
        }
     }
     return 1;
 }
int rec(int level){ 
   if(level==n){
     vector<string>ans;
     for(int i=0;i<n;i++){
        string str="";
        int pc=queens[i];
        for(int j=0;j<n;j++){
            if(j!=pc){
            str+='.';
            }else{
                str+='Q';
            }
        }
        ans.push_back(str);
     }
    //  for(int i=0;i<queens.size();i++){
    //     int pc=queens[i];
    //     ans[i][pc]='Q';
    //  }
     final_ans.push_back(ans);
     return 1;
   }
   // choice
   int ans=0;
   for(int ch=0;ch<n;ch++){
        if(check(level,ch)){
            //place our queens
            queens[level]=ch;
            //recursive call
          ans +=  rec(level+1);
            //unplace
            queens[level]=-1;
        }
   }
   cout<<ans<<endl;
   return ans;
}
//     vector<vector<string>> solveNQueens(int k) {
//    n=k;
//    int cnt=rec(0);
//    return final_ans;
       


//     }
    void solve(){
       cin>>n;
       cout<<n<<endl;
    //    vector<vector<string>>ans=solveNQueens(n);
    int ans=rec(0);
    cout<<ans<<endl;
       for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            cout<<final_ans[i][j]<<" ";
          }
          cout<<endl;
       }

    }
    signed main(){
        solve();
    }
