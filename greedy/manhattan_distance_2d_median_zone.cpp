//find where to meet
// find the minimum number of move to find the manhattan point
// find the median zone
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
   int n;
   cin>>n;
  int x[n],y[n];
   for(int i=0;i<n;i++){
    cin>>x[i];
   }
   for(int i=0;i<n;i++){
    cin>>y[i];
   }
  sort(x,x+n);
  sort(y,y+n);
   
   // find where to meet
 
   int index_median=n/2;

   if(n%2){
    // odd number of element
   int val_x=x[index_median];
   int val_y=y[index_median];
   // minimum move
   int minimum_move=0;
   for(int i=0;i<n;i++){
     minimum_move+=abs(val_x-x[i]);
     minimum_move+=abs(val_y-y[i]);
   }
   cout<<minimum_move<<endl;
   }else{
    // here we find the two median value
    // median zone
    int index1=n/2;
    int index2=n/2+1;
    // median value
    int median_val_x=x[index1];
    int median_val_y=y[index1];
    // minimum move or minimum manhattan distance to reach at common point where d is minimum
     int minimum_move=0;
      for(int i=0;i<n;i++ ){
        minimum_move+=abs(median_val_x-x[i]);
        minimum_move+=abs(median_val_y-y[i]);
      }
      cout<<"minimum move"<<minimum_move<<endl;
    // fesible value of x where manhattan distance is minimum (means where we got two value of median)
    int fesible_count_x=x[index2]-x[index1]+1;
    int fesible_count_y=y[index2]-y[index1]+1;
    cout<<"total number of solution"<<fesible_count_x*fesible_count_y<<endl;


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