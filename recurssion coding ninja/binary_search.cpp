#include<iostream>
using namespace std;
int bs(int a[],int si,int ei,int x){
    int mid=(si+ei)/2;
    if(si>ei){
        return -1;
    }
    if(a[mid]==x){
        return mid;
    }
    else if(a[mid]>x){
        bs(a,si,mid-1,x);
    }else{
        bs(a,mid+1,ei,x);
    }
}
int main(){
    int b[5]={1,2,3,4,5};
    bs(b,0,4,3);
}
