#include<bits/stdc++.h>
using namespace std;

int count(int x){
    if(x==0) return 0;
    cout<<(x&1)<<" "<<(x>>1)<<endl;
    return x&1 + count(x>>1);
}
int odd_occ(vector<int>arr){
    int n=arr.size();
    int ans=0;
  for(int i=0;i<32;i++){
    int sum=0;
    for(int j=0;j<arr.size();j++){
        sum+=(arr[j]&(1<<i));
    }
    if(sum%3){
        ans=ans|(1<<i);
    }
  }
   return ans;
}
bool isdivisible(int n,int k){
    int power2=1<<k;
    return n&(power2-1); 
}

void print(int x){
    for(int i=31;i>=0;i--){
        if((x>>i)&1){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
}



void solve(){
    int n;
    cin>>n;
  vector<int>arr;
   arr.assign(n,0);
   for(int i=0;i<n;i++){
    cin>>arr[i];
 
   }
//    cout<<odd_occ(arr)<<endl;
   for(int mask=0;mask<(1<<n);mask++){
    // total possiblity of subset of mask
     for(int pos=0;pos<n;pos++){
       if((mask>>pos)&1){
        // cout<<arr[pos]<<" ";
       }
     }
     cout<<endl;
   }
   // sum of all the subset of array
   // each number has the occurance of 2^(n-1);
   int sum=0;
   for(int mask=0;mask<(1<<n);mask++){
    cout<<"mask"<<mask<<endl;
      for(int pos=0;pos<n;pos++){
        if((mask>>pos)&1){
            cout<<arr[pos]<<" ";
            sum+=arr[pos];
        }
      }
      cout<<endl;
   }
   for(int mask=0;mask<(1<<n);mask++){
    
    for(int submask=mask;submask;submask=(submask-1)&mask){
        for(int i=0;i<pos;i++){
            b
        }
    }


   }

}
int main(){
    solve();
}