#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int convert_str_to_number(string number){
    int ans=0;
    for(int i=0;i<number.size();i++){
        ans=ans*10+(number[i]-48);
    }
    return ans;
  
}
bool is_prime( int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0) return false;
    }
    return true;
}
void solve(){
    int a,b;
    cin>>a>>b;
    int ans=0;
    
    for(int i=1;i<1e5;i++){
        string number=to_string(i);
        string number2=number;
        reverse(number2.begin(),number2.end());
        // here we two palindrome number first of even size 
        // 2nd of the odd size 
        int checknum1=convert_str_to_number(number+number2);
        // if(checknum1<a ||checknum1>b) // then  we dont have to check for prime number
        int checknum2=convert_str_to_number(number+number2.substr(1));
        if(checknum1>=a&&checknum1<=b){
            if(is_prime(checknum1)){
                cout<<checknum1<<" ";
                ans++;
            }
        }
        if(checknum2>=a&&checknum2<=b){
            if(is_prime(checknum2)){
                cout<<checknum2<<" ";
                ans++;
            }
        }
        
    }
    cout<<ans<<endl;

}
signed main(){
    solve();

}