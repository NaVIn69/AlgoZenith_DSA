#include <bits/stdc++.h>
using namespace std;
int S(int arr[],int arrLength){
    map<int,pair<int,int>>mpp;
   
    int first_index=INT_MAX;
    int maxi=0;
    for(int i=0;i<arrLength;i++){
        mpp[arr[i]].first=min(i,mpp[arr[i]].first);
        mpp[arr[i]].second++;
        maxi=max(mpp[arr[i]].second,maxi);
    }
    bool check=false;
    for(auto x:mpp){
        if(x.second.second!=1){
            check=true;
        }
    }
    if(check){
        for(auto v:mpp){
           if(v.second.second==maxi){
               first_index=min(first_index,v.second.first);
           }
        }
        return arr[first_index];
    }else{
        return -1;
    }
    

}

int main(){
    int arrlength;
    cin>>arrlength;
    int arr[arrlength];
    for(int i=0;i<arrlength;i++){
        cin>>arr[i];
    }
    cout<<S(arr,arrlength)<<endl;
}