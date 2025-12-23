#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
     // U ,D,L,R
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
void solve(){
    int w,h;
    cin>>h>>w;
    char arr[w+1][h+1];
    for(int i=1;i<=w;i++){
          string str;
          cin>>str;
        for(int j=1;j<=h;j++){
            arr[i][j]=str[j-1];
        }
    }
  if(w==1 || h==1){
    cout<<"NO"<<endl;
    return ;
  }
//     for(int i=1;i<=w;i++){
       
//       for(int j=1;j<=h;j++){
//            cout<<arr[i][j]<<" ";
//       }
//       cout<<endl;
//   }

    
// there should be ray in one direction 

    bool check=false;
    int cnt=0;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            if(arr[i][j]=='*'){
                // cout<<i<<" "<<j<<endl;
                 bool check=true;
                  for(int k=0;k<4;k++){
                    int ny=i+dy[k];
                    int nx=j+dx[k];
                    // cout<<nx<<" "<<ny<<endl;
                    if(nx>=1&&nx<=h&&ny>=1&&ny<=w){
                      
                       if(arr[ny][nx]=='.'){
                         check=false;
                         break;
                       }
                    }
                  }
                  if(check){
                   // here we hava to check about ray ,
                   int row=i,col=j;
                   bool fuck=false;
                  int col_left=1, col_right=h;
                  bool left=true;
                  bool right=true;
                  while(col_left<col||col_right>col){
                      if(col_left<col&&arr[row][col_left]=='.'){
                        left=false;
                      
                      }
                      if(col_right>col&&arr[row][col_right]=='.'){
                        right=false;
                        
                      }
                      col_left++;
                      col_right--;

                  } 
                  if(left||right){
                    // cout<<" col "<<i<<" "<<j<<endl;
                    cnt++;
                    continue;
                  }
                  int row_up=1,row_down=w;
                  left=true;
                  right=true;
                  while(row_up<row||row_down>row){
                     if(row_up<row&&arr[row_up][col]=='.'){
                        left=false;
                        
                     }
                     if(row_down>row&&arr[row_down][col]=='.'){
                        right=false;
                        
                     }
                     row_up++;
                     row_down--;
                  }
                    
                  if(left || right){
                    // cout<<"row "<<i<<" "<<j<<endl;
                    cnt++;
                  }
                  
                  }
            }
            if(cnt>1){
                cout<<"NO"<<endl;
                return ;
            }
        }
    }
    if(cnt==1){
        cout<<"YES"<<endl;
        return ;
    }
    cout<<"NO"<<endl;
}
signed main(){
    solve();
}