#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string s;
int n;
bool check_palindrome(vector<int>&num){
    
   int odd_cnt=0;
   for(int i=1;i<=9;i++){
       if(num[i]!=0){
       if(num[i]%2==0) continue;
       else odd_cnt++;
       if(odd_cnt>1) return false;
       }  
   }

   return true;
}
bool check(int len){
 vector<int>num(10,0);
   int sz=s.size();

   for(int i=0;i<len;i++){
      num[s[i]-48]++;
   }
 
   if(check_palindrome(num)){
    return true;
   }

   for(int i=0;i<sz-len;i++){
     
       num[s[i]-48]--;
       num[s[i+len]-48]++;

       if(check_palindrome(num)){
          return true;
       } 
   }

   return false;
}

void solve(){
    cin>>s;
    n=s.size();
    int ans=1;
    int l=0;
    int h=s.size();
    while(l<=h){
      int mid=l+(h-l)/2;

       if(check(mid)){
       
         ans=mid;
           l=mid+1;
       }else{
         h=mid-1;
       }
    }
    cout<<ans<<endl;
    

}
signed main(){
    solve();
}