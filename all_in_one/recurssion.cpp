#include<bits/stdc++.h>
using namespace std;

// lccm 
// l -> level, c-> choice , c-> check m -> move

int n,m,k;
int ans=0;
void tower_hanoi(int x, char source,char aux, char target){
      if(x==0) return ;
      ans++;
      tower_hanoi(x-1,source,target,aux);
      cout<<x<<" "<<"move"<< source<<" to "<<target<<endl;
      tower_hanoi(x-1,aux,source,target);
}

vector<int>sol;
void rec_all_subset(vector<int>&arr,int level){
    if(level==n){
        // 
        if(sol.size()==k){
            for(auto v:sol){
                cout<<v<<" ";
            }
            cout<<endl;
            return ;
        }
        return ;
    }

    // choice 
    // here we have two choice either take it or dont take it
    // take it
    if(sol.size()<k){
        sol.push_back(arr[leve]);
        rec(level+1); // move
        sol.pop_back() // unplace    it is most important 
    }
    // here we dont take the element 
    rec(level+1);
}

void all_subset_size_k(vector<int>&arr,int k){
     rec(arr,0);
}


int cnt=0;
vector<vector<char>>mat;
vector<int>queens(n,-1);// for evry row we have the column

bool check(int row,int col){
    // here we have to check like 
   for(int pr=0;pr<row,pr++){
      int pc=queens[pr];
      if(pc==col || abs(row-pr)==abs(col-pc)){
        return false;
      }
   }
   return true;
}

int rec_n_queens(int level){
    if(level==n){
        // means we have been place all the queens in the row like , they dont attack each other
      for(int i=0;i<queens.size();i++){
         cout<<queens[i]<<" ";
      }

      return 1;
    }
    // choice int every column of that row
    /// choice
    int cnt=0;
    for(int i=0;i<m;i++){
        // check 
        if(check(level,i)){
            // place
            queens[level]=i;
            // move
            cnt+=rec(level+1);
            // unplace
            queens[level]=-1;
        }

    }
    return cnt;

}

// generate all the premutation
vector<int>curr_prem;
vector<vector<int>>all_sol;
map<int,int>mpp;

void rec(int level){
   if(level==n){
    all_sol.push_back(curr_prem);
    return ;
   }
   for(auto &x:mpp){
      if(x.second!=0){
        curr_prem.push_back(x.first);
        x.second--;
        rec(level+1);
        curr_prem.pop_back();// unplace
        x.second++;
      }
   }
}
void generate_all_prem(vector<int>&arr){
    map<int,int>mpp;
    for(int x:arr){
        mpp[x]++;
    }


}


// total number of ways to place the k knights on the chess board
int ans=0;
int board[14][14];
int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={-1,-2,-2,-1,1,2,2,1};
bool check(int row, int col){
    if(board[row][col]==1) return;
     for(int pos=0;pos<8;pos++){
         int nx=row+dx[i];
         int ny=col+dy[i];
         if(nx>=0&&nx<=14&&ny>=0&&ny<=14&&board[nx][ny]==1){
             return false;
         }
     }
     return true;
}
int rec(int level){
    // here we have been placed all the k Knights
     if(level==k){
        //   ans++;
          return 1;
     }
     // choice 
     // each cell is the my choice 
     int ans=0;
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
              if(check(i,j)){
                 // can we place the knight at that palce
                 board[i][j]=1;
                ans+= rec(level+1);
                 board[i][j]=0;
              }
         }
     }
     return ans;

}

//.......................................//
// generate all the balanced paranthesis of size n
int n;
vector<string>ans;
string str="";

vod rec_balanced_param(int open,int close){
     if(open==close&&open+close=(2*n)){
        ans.push_back(str);
        return ;
     }

     // choice // first taken the open bracket 
     if(open<n){
        str+='(';
        rec_balanced_param(open+1,close);
        str.pop_back();
     }
     if(close<open){
        str+=')';
        rec_balanced_param(open,close+1);
        str.pop_back();
     }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// find the kth move the tower of hanoi

void move(int disks, int currentpeg, int moveto ,int helper){
     if(disks==0) return ;
     move(disks-1,currentpeg,helper,moveto);
     court<<disks<<" "<<currentpeg<<" "<<moveto<<endl;
     move(disks-1,helper,moveto,currentpeg);
}
void movekth(int disks,int currentpeg, int moveto,int helper){
       if(disks==0) return ;
       if(k<(1<<(disks-1))-1){
          movekth(disks-1,currentpeg,helper,moveto);
       }else if(k==((1<<(disks-1)))){
          cout<<"move disks "<<disks <<" "<<currentpeg<<" "<<moveto<<endl;

       }else{
        movekth(disks-1,helper,moveto,currentpeg);
       }
}

// here we have to findout the kth permutation of array 
// 13!>= 10^9 then only 13 element is going to rearrange , remaing (n-13) element will be the same

void kth_permutation(vector<int>&arr, int k){
    // first find the (n-1)! then k/(n-1)! tell me which is going to be the first element of permutation
    int fact=1;
    for(int i=1;i<n;i++){
         fact=i*fact;
    }
    k--;
    vector<int>ans;
    while(1){
        int index=k/fact;
        ans.push_back(arr[index]);
        arr.erase(arr.begin()+index);
        if(arr.size()==0) return ;
        fact=fact/arr.size(); //-> converting (n-1)! -> (n-2)!
    }

    
}

int boardsize=9;
int cellsize=3;
int board[9][9];

bool check(int val, int row,int col){
    // here first we have to check into that row col
    for(int i=0;i<9;i++){
        if(board[i][col]==val) return false;
        if(board[row][i]==val)return false;
    }
    // check for that cellsize
    int st_row=(row/cellsize)*cellsize;
    int st_col=(col/cellsize)*cellsize;
    for(int dx=0;dx<cellsize;dx++){
         for(int dy=0;dy<cellsize;dy++){
             if(st_row+dx==row&&st_col+dy==col) continue;
             if(board[st_row+dx][st_col+dy]==val) return false;
         }
    }
    retur true;
}
void rec_sudoku_solver(int row,int col){
     if(col==boardsize){
        rec(row+1,0);
        return;// we reach at the last of the column then col becomes 0
     }
     // base case
     if(row==boardsize){
        // here we have been solved the board
        for(int i=0;i<boardsize;i++){
             for(int j=0;j<boardsize;j++){
                 cout<<board[i][j]<<" ";
             }
             cout<<endl;
        }
        return  ;
     }

     // here we choice
     if(board[row][col]==0){
     for(int i=1;i<=9;i++){
         // can we place i at the row, col
         if(check(i,row,col)){
             board[row][col]=i;
             rec(row,col+1);
             board[row][col]=0;
         }
     }
    }else{
        // prefilled then check it is valid or not 
         if(check(board[row][col],row,col)){
             rec(row,col+1);
         }
    }

}

// 4 sum problem

vector<int>4sum(vector<int>&arr,int target){
     map<int,pair<int,int>>mpp; // sum-> {i,j}

     for(int b=n-2;b>=1;b--){
          for(int a=b-1;a>=0;a--){
              if(mpp.find(target-arr[a]-arr[b])!=mpp.end()){
                  return {a,b,mpp[target-arr[a]-arr[b]].second.first,mpp[target-arr[a]-arr[b]].second.second};
              }
          }
          int c=b;
          for(int d=c+1;d<n;d++){
             mpp[arr[c]+arr[d]]={c,d};
          }
     }
}

bool 3sum(vector<int>&arr, int target){
     sort(arr.begin(),arr.end());
     for(int j=0;j<n;j++){
        int i=0;
        int k=n-1;
        int rem=target-arr[j];
        // this is more like two sum problem
        while(i<j&&k>j){
            if(arr[i]+arr[j]==rem){
                 return true;
            }else if(arr[i]+arr[j]>rem){
                j--;
            }else{
                i++;
            }
        }
     }
     return false;
}







void solve(){
    int n;
    cin>>n;
    tower_hanoi(n,'A','B','C');
    cout<<ans<<endl;

}
int main(){
    solve();
}