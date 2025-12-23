#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;

int binpow(int a,int b){
    int ans=1;
    while(b){
        if(b%2){
            ans=(ans%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod);
        b/=2;
    }
    return ans;
}

struct running_mean_median_mode{
    int sum=0;
    int sqsum=0;
    int cnt=0;
    multiset<int>smaller,larger; // for median
    map<int,int>freq; // for mode , for maintaing the mode
    multiset<pair<int,int>>freq_order; // here we are maintaing the freq_order for mode here in pair we have the {freq[x],x}

    void balanced(){
        if(smaller.size()>larger.size()+1){
            int x=*smaller.rbegin();
            larger.insert(x);
            smaller.erase(smaller.find(x));
        }else if(smaller.size()<larger.size()){
            int x=*larger.begin();
            smaller.insert(x);
            larger.erase(larger.find(x));
        }

    }
    void insert(int x){
        // mean
        sum+=x;
        sqsum+=(x*x);
        cnt++;

        // median
        if(smaller.empty()) smaller.insert(x);
        else if(x<=*smaller.rbegin()){
            smaller.insert(x);
        }else{
            larger.insert(x);
        } 
        
        // mode
        if(freq_order.find(make_pair(freq[x],-x))!=freq_order.end()){
             freq_order.erase(freq_order.find(make_pair(freq[x],-x)));
        }
        
        freq[x]++;
        freq_order.insert(make_pair(freq[x],-x));

        balanced();
    }

    void remove(int x){
        // mean
        sum-=x;
        sqsum-=(x*x);
        cnt--;
        
        // median
        if(x<=*smaller.rbegin()){
            smaller.erase(smaller.find(x));
        }else{
          larger.erase(larger.find(x));
        }
        // mode
         if(freq_order.find(make_pair(freq[x],-x))!=freq_order.end()){
             freq_order.erase(freq_order.find(make_pair(freq[x],-x)));
        }
        freq[x]--;
        freq_order.insert(make_pair(freq[x],-x));

        balanced();  
    }

    int get_mean(){
    if(cnt == 0) return -1;
    int ans = sum % mod * binpow(cnt, mod - 2) % mod;
    return (ans + mod) % mod;
}

   int get_median(){
        if(cnt==0) return -1;
         if (smaller.size() > larger.size()) {
            return *smaller.rbegin();
        } else {
           return ((*smaller.rbegin() + *larger.begin()) % mod * binpow(2, mod - 2) % mod + mod) % mod;

        }
    }

    int get_mode(){
        if(cnt==0) return -1;
        // if(freq_order.rbegin()->first==freq_order.begin()->first){
        //     // cout<<'nav'<<endl;
        //     return -1*freq_order.begin()->second;
        // }
        return -1*freq_order.rbegin()->second;

    }

    double get_varience(){
        if(cnt==0) return -1;
        double ans=sqsum/cnt;
        int mean=get_mean();
        return ans-mean*mean;
    }

};
void solve(){
    int q;
    cin>>q;
    running_mean_median_mode md;
    while(q--){
        string ch;
        cin>>ch;
        if(ch=="insert"){
            int x;
            cin>>x;
            md.insert(x);
        }else if(ch=="remove"){
            int x;
            cin>>x;
            md.remove(x);
        }else if(ch=="getMean"){
            cout<<md.get_mean()<<endl;

        }else if(ch=="getMedian"){
            cout<<md.get_median()<<endl;

        }else if(ch=="getMode"){
            cout<<md.get_mode()<<endl;

        }
    }

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}