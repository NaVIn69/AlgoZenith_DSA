#include<bits/stdc++.h>
using namespace std;
int sqr1(long int n){
 long int s=0;
 long int e=n;
 long int ans=-1;
 while(s<=e){
   long int mid=(s+e)/2;
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
double moreprecision(long int n,int presicion,int tempsol){
    double factor=1;
    double ans=tempsol;
    for(int i=0;i<presicion;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans+=j;
        }
    }
    return ans;
}
void solve(){
int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    long int diff_x=abs(x1-x2);
    long int diff_y=abs(y1-y2);
     double mahhattan_d=diff_x+diff_y;
    long int euclidean_d=diff_x*diff_x+diff_y*diff_y;
    int sq=sqr1(euclidean_d);
   double ans=moreprecision(euclidean_d,8,sq);
   cout<<fixed<<setprecision(7)<<ans<<" ";
    cout<<fixed<<setprecision(7)<<mahhattan_d<<endl; 

}
int main(){
   int t;
    cin>>t;
    while(t--){
solve();
    }

}