#include<bits/stdc++.h>
using namespace std;
int peak(vector<int>&nums){
    int s=0;
    int ans=-1;
    int e=nums.size()-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(nums[mid]<nums[mid+1]){
            s=mid+1;
        }else if(nums[mid]>nums[mid+1]){
            e=mid;
        }else if(nums[mid]>nums[mid-1]&&nums[mid]<nums[mid+1]){
            ans=mid;
        }
    }
    return ans;
}
int main(){
    int arr[4]={3,4,5,1};
    cout<<peak(arr);
}