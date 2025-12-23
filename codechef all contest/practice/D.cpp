#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       int arr[n];
       int index_check=-1;// all odd then no even
       for(int i=0;i<n;i++){
           cin>>arr[i];
           if(arr[i]%2==0){
                index_check=i;
           }
       }
       int cnt=0;
       bool check=true;
       int index=0;
       for(int i=n-1;i>=0;i--){
           if(arr[i]%2==0){
             continue;
           }else{
              index=i;
               cnt+=(i+1);
               break;
           }
       }
       // nearest even number of every odd number
       vector<int>v;
       stack<int>st;

for(int i=0;i<n;i++){
    if(arr[i]%2==0){
        st.push(i);
        continue;
    }
while(!st.empty()&&arr[st.top()]%2!=0){
 st.pop();
}
if(st.empty()){
    v.push_back(0);
}else{
    v.push_back(st.top()+1);
  
}
st.push(i);

}
// all odd
for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
     if(v[i]==index){
        continue;
     }
    cnt+=v[i];
}

  for(int i=n-1;i>=0;i--){
    if(arr[i]%2==0){
       
        cnt+=(i+1);
    }
  }
  cout<<cnt<<endl;
   }
}
