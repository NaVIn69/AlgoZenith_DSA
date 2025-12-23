#include<iostream>
using namespace std;
bool is_sorted(int arr[],int size){
    if(size==0||size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        return true;
    }
    bool issmallsorted=is_sorted(arr+1,size-1);
    return issmallsorted;
}
int main(){
    int arr[6]={1,1,0,4,5,6};
    bool output=is_sorted(arr,6);
    cout<<output<<endl;
}