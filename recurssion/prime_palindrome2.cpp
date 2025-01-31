#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool is_prime(int n){
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int cnt_digit(int n){
    if(n<=9) return 1;
    return cnt_digit(n/10);
}
int convert_str(string s){
    int ans=0;
    for(int i=0;s[i]!='\0';i++){
          ans=ans*10+(s[i]-48);
    }
    return ans;
}
void solve(){
    int a,b;
    cin>>a>>b;
    int ans=0;

    //here 11 is the edge cse that why we are taking it ans indivivually
    // if(a<=11 &&b>=11) ans++;
    // for(int i=1;i<1e5;i++){
    //     string str=to_string(i);
    //     string rev=str;
    //     reverse(rev.begin(),rev.end());
    //     int check_num=convert_str(str+rev.substr(1));
    //     if(check_num<a||check_num>b) continue;
    //     if(is_prime(check_num)){
    //         cout<<check_num<<endl;
    //         ans++;
    //     }
        
    // }
    if(a<=99){
       
        for(int i=a;i<=9;i++){
            if(is_prime(i)){
               
                ans++;
            }
        }
    }
    int digit=cnt_digit(b)/2;
    for(int i=1;i<1e5;i++){
        if(i>b) break;
        string str=to_string(i);
        string rev=str;
        reverse(rev.begin(),rev.end());
        string str3=str+rev;
        int num3=convert_str(str3);
        if(num3>=a&&num3<=b){
        if(is_prime(num3)){
           
            ans++;
        }
        }
        for(int i=0;i<=9;i++){
            string s3=to_string(i);
             string check="";
             check=str+s3+rev;
           
             int num=convert_str(check);
         
             if(num>b) break;
             if(num<a ||num>b) continue;
             if(is_prime(num)){
             
                ans++;
             }

        }
    }
    cout<<ans<<endl;


}
signed main(){
    solve();
}