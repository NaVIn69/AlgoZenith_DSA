#include<iostream>
using namespace std;
int lastindex(int arr[],int n,int x){
    if(n==0){
        return -1;
    }
    int smalloutput=lastindex(arr+1,n-1,x);
    if(arr[smalloutput+1]==x){
        return smalloutput+1;
    }
    if(smalloutput==-1){
        return -1;
    }
    else{
        return smalloutput+1;
    }
}