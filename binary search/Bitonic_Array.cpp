#include<bits/stdc++.h>
using namespace std;
int binarysearch(int*a,int s1,int e1,int x){
    int s=s1;
    int e=e1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==x){
            return mid;
        }else if(a[mid]>x){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return -1;
}
int binarysearch_rev(int*a,int s1,int e1,int x){
    int s=s1;
    int e=e1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==x){
            return mid;
        }else if(a[mid]>x){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return -1;

}

int check1(int*a,int mid,int n){
    if(mid==n-1) return 1;
    if(a[mid]>a[mid+1]){
        return 1;
    }else{
        return 0;
    }
   }
int peakelement(int*a,int n){
     int s=0;
   int e=n-1;
   int ans=0; 
   while(s<=e){
    int mid=s+(e-s)/2;
    if(check1(a,mid,n)==1){
      ans=mid;
      e=mid-1;
    }else{
        s=mid+1;
    }
   }
   return ans;

}
void bitonic_array(int*a,int k,int n){
    int peak=peakelement(a,n);
    int ans=-1;
    int ans1=-1;
    if(k==a[peak]){
        cout<<peak+1<<endl;
        return;
    }
    
    
     if(k<a[peak]&&k>=a[0]){
         ans=binarysearch(a,0,peak-1,k);
    }
    if(k<a[peak]&&k>=a[n-1]){
         ans1=binarysearch_rev(a,peak+1,n-1,k);
    }
    if(ans!=-1&&ans1!=-1){
        cout<<ans+1<<" "<<ans1+1<<endl;
    }else if(ans!=-1){
        cout<<ans+1<<endl;
    }else if(ans1!=-1){
        cout<<ans1+1<<endl;
    }
    
    
}
void solve(){
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(q--){
        int k;
        cin>>k;
        bitonic_array(a,k,n);
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}