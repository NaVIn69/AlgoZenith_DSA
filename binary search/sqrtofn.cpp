#include<iostream>
using namespace std;
int sqrt(int n){
 int s=0;
 int e=n;
 int ans=-1;
 while(s<=e){
    int mid=(s+e)/2;
    long long int square=mid*mid;
    if(square==n){
        return mid;
    }
    if(square>n){
        e=mid-1;
    }else{
        ans=mid;
        s=mid+1;
    }
 }
 return ans;
}
double moreprecision(int n,int presicion,int tempsol){
    double factor=1;
    double ans=tempsol;
    for(int i=0;i<presicion;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    // cout<<sqrt(n)<<endl;
    int s=sqrt(n);
    cout<<s<<endl;
    cout<<"answer is "<<moreprecision(n,4,s);

}