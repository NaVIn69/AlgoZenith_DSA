// given infinte series of string which contain 0 and  1 
// 0 1 10 11 100 101 110 111 1000 1001 1010 1011  this is string which is the binary re presentation of number [0 - n]
// 0 1  2  3  4   5   6   7    8    9    10   11   like this 
// we have to find the kth 1's in the infinte string  means we have to find the real position of kth 1's in infinte series of the string 
// here we solve for constraint 
// 1. q<=10^5 k<=10^5
// 2. 1<=105  k<=10^9

// solution for 1 question
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string get_bit_str(int num){
    string ans="";
    while(num){
       if(num&1){
        ans+="1";
       }else{
        ans+="0";
       }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
void solve(){
    // given infnite string
    
    // k is upto 10^5 means at least each  decimal number have atleast  one (1)
    // we make precomputtion string 
    string str_upto_n="";
    int num=0;
    // here we precompute the string
    int cnt_one=0;
    while(num<=100000){
        string s=get_bit_str(num);
        // here string in order left to right means 31 bit to 0 at max
        for(auto v:s){
            if(v=='1'){
                cnt_one++;
            }

        }
        str_upto_n+=s;
    }
    // and here we store the index where 1 is present in infinte string(precompute string)
    vector<int>index_one;
    for(int i=0;i<str_upto_n.size();i++){
           if(str_upto_n[i]=='1'){
            index_one.push_back(i);
           }
    }
    int q;
    cin>>q;
    while(q--){
        // kth 1's in real string
        int k;
        cin>>k;
        cout<<index_one[k-1]<<endl;
    }


}
signed main(){

}
