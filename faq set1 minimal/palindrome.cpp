#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    string s;
    cin>>s;
    bool check=true;
    if(s.size()<=2){
        cout<<"Y"<<endl;
        return ;
    }
    int i=0;
    int j=s.size()-1;
    int cnt=0;

    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
            continue;
        }else{
            check=false;
            break;
        }
    }
    if(check){
        cout<<"Y"<<endl;
        return;
    }
    //here length of remaining string
    //here we have to check
    int len=j-i;
    //here we deleting the ith character of 
    bool check2=true;
    int i1=i;
    int j1=j-1;
    while(i1<j1){
        if(s[i1]==s[j1]){
            i1++;
            j1--;
            continue;
        }else{
            check2=false;
            //means not palindrome
            break;
        }
    }

   int i2=i+1;
   int j2=j;
   bool check3=true;
    while(i2<j2){
        if(s[i2]==s[j2]){
            i2++;
            j2--;
            continue;
        }else{
            check3=false;
            //means not palindrome
            break;
        }
    }
    if(check2 || check3){
        cout<<"Y"<<endl;
    }else{
        cout<<"N"<<endl;
    }

   
  

    

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
