#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int queens[100];
vector<vector<string>>final_ans;
void printer(){
    for(int i=0;i<n;i++){
        cout<<queens[i]<<" ";
    }
    cout<<endl;
}

bool check(int row,int col){
    // we have to check in the previous row and col 
    // attack kr rha hai yha nhi
  
    for(int pr=0;pr<row;pr++){
         
        int pc=queens[pr];
        if(pc==col || abs(pr-row)==abs(pc-col)){
            return 0;
        }
    }
    return 1;
}
int rec(int level){
    // here we have been placed the queens in 0.....level-1
    // now we are checking for that level and exploring all the choice for that level
    //base case
    if(level==n){
        vector<string>namo;
        for(int i=0;i<n;i++){
            int pc=queens[i];
            string str="";
            for(int j=0;j<n;j++){
                if(j!=pc){
                    str+='.';
                }else{
                    str+='Q';
                }
            }
            namo.push_back(str);
        }
        // cout<<"level"<<" "<<level<<endl;
        final_ans.push_back(namo);
        return 1;
    }

    // recursive case
    // choice
    int ans=0;
    for(int ch=0;ch<n;ch++){
        // cout<<"choice"<<" "<<"at "<<level<<" "<<ch<<endl;
        // checking for every choice and here we are checking it
        if(check(level,ch)){
            // cout<<"valid choice at "<<level<<endl;
            //place the queens at that place
            queens[level]=ch;
            // move the recursive solution
          ans += rec(level+1);
          // after exploring all the solution from that
          // we place that plac
          queens[level]=-1;
        }
    }
    // cout<<"answer"<<" at "<<level<<" "<<ans<<endl;
    return ans;

}
void solve(){
    cin>>n;
    memset(queens,-1,sizeof(queens));
   
    for(int i=0;i<final_ans.size();i++){
        for(int j=0;j<n;j++){
            cout<<final_ans[i][j]<<" ";
        }
        cout<<endl;
    }
 
}

signed main(){
    solve();
}