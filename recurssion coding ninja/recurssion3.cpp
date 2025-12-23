#include<iostream>
using namespace std;
int count(int n){
    if(n==0){
        return 0;
    }
    int smalloutput=count(n/10);
    int ans=smalloutput+1;//jab tak memory deleat naa ho jai tab tak return krega
    return ans;

}
int main(){
    int x;
    cin>>x;
    int output=count(x);
    cout<<output;

}
