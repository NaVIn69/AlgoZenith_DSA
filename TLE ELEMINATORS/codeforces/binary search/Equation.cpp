#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define endl "\n"

// x^2+sqrt(x)=c;
bool check(ld mid,ld c){
    return mid*mid+sqrt(mid)>=c;
}
void solve(){
    ld c;
    cin>>c;

    if(c==2.0){
        cout<<1.00<<" ";
        return ;
    }


    ld l=0.0;
    ld h=1.0L;
    while(check(h,c)==false){
        h=h*2.0L;
    }
    ld ans=0.0L;
    ld EPS=1e-8;
    while(abs(h-l)>=EPS){
        ld mid=(l+h)*(0.5L);
        if(check(mid,c)){
            ans=mid;
            h=mid;
        }else{
            l=mid;
        }
    }
    cout<<fixed<<ans<<setprecision(8)<<endl;


}
int main(){
    solve();
}