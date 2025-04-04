#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
map<int,int>mpp;
vector<int>sol;
bool check_prime(int num){
    if(num<2) return false;
  
    for(int i=2;i*i<=num;i++){
        if(num%i==0) return false;
    }
    return true;
}
// these two are shared across the recursion
int rec(int level,int prev){
    // this function tells me about on which level i am at and we have been stored the previous , because of checking the parity of that previous number
    if(level==n+1){
        // here we have to check that what we have been obtain the solution 
   
    
        int first_two_pair_sum=sol[0]+sol[1];
        if(check_prime(first_two_pair_sum)==false) return 0;
        // if(check==false) return 0;
        for(int i=2;i<n;i++){
               first_two_pair_sum-=sol[i-2];
               first_two_pair_sum+=sol[i];
               if(check_prime(first_two_pair_sum)==false){
                return 0;
           
        }
        
      
    }
    // for(int i=0;i<sol.size();i++){
    //     cout<<sol[i]<<" ";
    // }
    return 1;
}
    // choice 
    // if previous number is odd then we have to put next number should be even
    int ans=0;
    if(prev&1){
        // odd;
        for(int i=2;i<=n;i+=2){
            // choice to put 
            // either we put the i and check it then move to the next 
            // or place that 
           if(mpp.find(i)==mpp.end()&&check_prime(prev+i)){
              sol.push_back(i);
              mpp[i]++;
              ans+=rec(level+1,i);
              sol.pop_back();
              mpp.erase(i);
           }
        }
    }else{
        // here if previous value is even , then we have to place the odd number
        for(int i=1;i<=n;i+=2){

            if(mpp.find(i)==mpp.end()&&check_prime(prev+i)){
                sol.push_back(i);
                mpp[i]++;
                ans+=rec(level+1,i);
                sol.pop_back();
                mpp.erase(i);
            }  
        }
    }
    return ans;

}
void solve(){
  cin>>n;
  if(n==2){
    cout<<"1"<<endl;
    return ;
  }
  if(n==3){
    cout<<"0"<<endl;
    return ;
  }
//   if(n)
  sol.push_back(1);
  mpp[1]++;
  int ans=rec(2,1);
  cout<<ans<<endl;
//   cout<<check_prime(9)<<endl;

}
signed main(){
    solve();
}