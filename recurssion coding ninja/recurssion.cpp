#include<iostream>
using namespace std;
int pow(int x,int n){
    if(n==0){
        return 1;
    }
    int smalloutput=pow(x,n-1);
    return x*smalloutput;
}
int main(){
    int x,n;
    cin>>x>>n;
    int output=pow(x,n);
    cout<<output<<endl;

}