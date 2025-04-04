#include<bits/stdc++.h>
using namespace std;
int main(){
 char a[]={'n','m','n','o','\0'};
 int x=0,h=0;
 for(int i=0;a[i]!='\0';i++){
    x=1;
    x=x<<(a[i]-97);
    if(x&h>0){
        cout<<a[i]<<" ";
    }else{
        h=x|h;
    }
 }
 
}na