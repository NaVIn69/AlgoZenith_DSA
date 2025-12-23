#include<iostream>
using namespace std;
int multiplynumber(int m,int n){
    static int sum=0;
    if(m==0||n==0){
        return 0;
    }
    if(n>=m){
    if(m!=0){
        sum+=n;
    }
    int smalloutput=multiplynumber(m-1,n);
}
    else{
        if(n!=0){
            sum+=m;
        }
        int smalloutput1=multiplynumber(m,n-1);
    }

    return sum;
}
int main(){
    int n,m;
    cin>>m>>n;
    cout<<multiplynumber(m,n);
}