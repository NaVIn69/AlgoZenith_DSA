#include<bits/stdc++.h>
using namespace std;
int binarysearch(int *arr,int s,int e,int target){
int start=s;
int end=e;
int ans=-1;
while(start<=end){
    int mid=s+(e-s)/2;
    if(arr[mid]==target){
      ans=mid;
      break;
    }else if(target>arr[mid]){
     s=mid+1;
    }else{
        e=mid-1;
    }
}
return ans;
}
int lower_bound(int *arr,int s,int e,int target){
   
    int ans=e+1;
    while(s<=e){
      int mid=s+(e-s)/2;
      if(arr[mid]==target){
        ans=mid;
        e=mid-1;
      }else if(arr[mid]>target){
        ans=mid;
        e=mid-1;
      }else{
        s=mid+1;
      }
    }
    return ans;
}
int upper_bound(int* arr,int s,int e,int target){
    int ans=e+1;
    while(s<=e){
      int mid=s+(e-s)/2;
      if(arr[mid]>target){
        ans=mid;
        e=mid-1;
      }else{
        s=mid+1;
      }
    }
    return ans;
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n,target;
        cin>>n>>target;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<binarysearch(a,0,n-1,target);
    }

}
