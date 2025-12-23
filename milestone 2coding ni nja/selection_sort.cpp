#include<iostream>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=arr[i];
        int miniindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                miniindex=j;
            }
        }
        //swap;
        int temp=arr[i];
        arr[i]=arr[miniindex];
        arr[miniindex]=temp;
    }
}
int main(){
    int input[7]={3,1,7,4,9,0,2};
    selectionsort(input,7);
    for(int i=0;i<7;i++){
        cout<<input[i]<<" ";
    }
}