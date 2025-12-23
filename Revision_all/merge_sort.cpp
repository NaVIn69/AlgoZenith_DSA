#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int inversion_cnt=0;

void merge(vector<int>&arr,int low,int mid,int high){
    vector<int>temp;
    int left=low ; // we have to sorted array low -> mid , secodn -> mid+1 -> high
    int right=mid+1;
    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            // here we can count the inversion like 
            // left<right and arr[left]>arr[right] // it means all the pair is (left,(mid+1,right));
            // total number of swap in the bubble sort is same as the total number of inversion in the merge sort 
         
            
            temp.push_back(arr[right]);
            right++;
        }
    }
    // remianing element in the left side
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    // trannfering from temp to arr
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}


void mergesort(vector<int>&arr,int low,int high){
    if(low>=high) return ;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        // cout<<v[i]<<" ";
    }
    mergesort(v,0,n-1);
    for(auto c:v){
        cout<<c<<" ";
    }
    cout<<endl;
    cout<<inversion_cnt<<endl;


}
signed main(){
    solve();
}