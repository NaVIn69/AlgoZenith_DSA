#include<iostream>
#include<math.h>
using namespace std;
double geometricsum(int n){
    if(n==0){
        return 1;
    }
    double smalloutput=geometricsum(n-1);
    double output=smalloutput+1/(double)pow(2,n);
    return output;
}
int main(){
    int n;
    cin>>n;
    cout<<geometricsum(n)<<endl;
}