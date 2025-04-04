#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we given n , we have to find all the solution which gives me abcde/fghij == n 
void option_one(int n){
  // here we generate all the solution /means all the premutation 
  int arr[10]={0,1,2,3,4,5,6,7,8,9};
  do{
    int abcde=10000*arr[0]+1000*arr[1]+100*arr[2]+10*arr[3]+1*arr[4];
   int fghij= 10000*arr[5]+1000*arr[6]+100*arr[7]+10*arr[8]+1*arr[9];
   if(abcde%fghij==0){
    if(abcde/fghij==n){
        cout<<abcde<<" "<<fghij<<endl;
    }
   }

  }while(next_permutation(arr,arr+10));

}
void option_two(int n){
    // here abcde belong to 01234 to 98765 // because it has to be unique and
    // fghij belons to 01234/n to 98765/n // range of my fghij to be
    for(int fghij=1234;fghij<=98765/n;fghij++){
         set<int>st;
         int abcde=fghij*n;
         int temp=abcde;
         for(int i=0;i<5;i++){
            st.insert(temp%10);
            temp=temp/10;
         }
         temp=fghij;
         for(int i=0;i<5;i++){
            st.insert(temp%10);
            temp=temp/10;

         }
         if(st.size()==10){
            cout<<abcde<<" "<<fghij<<endl;
         }
    }
}
void solve(){
  int n;
  cin>>n;
//   option_one(n);
  option_two(n);
}
signed main(){
    solve();
}