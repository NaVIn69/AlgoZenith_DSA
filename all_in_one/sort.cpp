#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>&arr){
    int n=arr.size();
    // we set the larger element at the last element
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

void selection_sort(vector<int>&arr){
    int n=arr.size();
      // starting me smallest element ko set krte hai
      for(int i=0;i<n;i++){
        int minidx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minidx]) minidx=i;
        }
        swap(arr[i],arr[minidx]);
      }
}


// here we have {0.....i} tak sorted and i se n-1 tak unsorted
void insertionSort(vector<int>&arr){
     int n=arr.size();
     for(int i=1;i<n;i++){
        int key=arr[i];// here we have to place this at the right place in the leftside(sorted)
        int j=i-1;
        cout<<"key"<<key<<endl;
        // here we have been shifted all the elements of sorted array in the right of sorted array
        while(j>=0&&arr[j]>key){
            cout<<arr[j]<<" ";
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        cout<<arr[j+1]<<endl;
        cout<<endl;
     }

}

void merge(vector<int>&arr,int l,int mid,int r){
    vector<int>temp(r-l+1);
    int i=l,n=mid+1,j=mid+1,m=r+1;
    int k=0;
    while(i<n&&j<m){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    // remaning element
    while(i<n){
        temp[k++]=arr[i++];
    }
    while(j<m){
        temp[k++]=arr[j++];
    }
    for(int i=0;i<temp.size();i++){
         arr[i+l]=temp[i];
        //  cout<<temp[i]<<" ";
    }
    // cout<<endl;

}
void mergesort(vector<int>&arr,int l,int r){
       if(l==r) return ;
    int mid=(l+r)/2;
    mergesort(arr,l,mid); // this give me sorted array from l to mid index
    mergesort(arr,mid+1,r); // this give me sorted array from mid+1 to r
    merge(arr,l,mid,r); // here we are merging these both array into sorted array from l to r
}

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    // bubble_sort(arr);
   // insertionSort(arr);
    for(auto x:arr){
        cout<<x<<" ";
    }
    cout<<endl;

}

int main(){
  solve();
}