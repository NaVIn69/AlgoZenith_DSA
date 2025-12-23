#include<iostream>
using namespace std;
void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main(){
    int a[7]={10,5,1,15,8};
    bubblesort(a,7);
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
}