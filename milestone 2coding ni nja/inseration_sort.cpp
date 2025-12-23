#include<iostream>
using namespace std;
void inseration_sort(int arr[],int n){
for(int i=1;i<n;i++){
    int current =arr[i];
    int j;
    for( j=i-1;j>=0;j--){
        if(current<arr[j]){
            arr[j+1]=arr[j];
        }else{
            break;
        }
    }
    arr[j+1]=current;
}
}
int main(){
    int a[8]={9,6,3,8,2,0,1,7};
    inseration_sort(a,8);
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}