#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
void merge(int l,int mid,int r){
    int left_sz=mid-l+1;
    int right_sz=r-mid;
    vector<int>left(left_sz);
    vector<int>right(right_sz);
    ///left array
    for(int i=0;i<left_sz;i++){
        left[i]=arr[i+l];
    }
    //right array
    for(int i=0;i<right_sz;i++){
        right[i]=arr[i+mid+1];
    }

    int 

}
void mergeSort(int l,int r){
    if(l>=r){
        return ;
    }
    int mid=(l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merge(l,mid,r);
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

}
signed main(){
    solve();
}