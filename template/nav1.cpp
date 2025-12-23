#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod = 1e9+7;

long long binPow(long long a,long long b,int mod){
      long long res=1;
     
      while(b>0){
         if(b&1)
            res =(res*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
       }
   return (res+mod)%mod; 
}
struct dashboard_data{
    // mean
    int sum = 0;
    int cnt=0;
    // variance
    int sumSq = 0;
    
    // median
    multiset<int> low,high;
    
    // mode
    map<int,int> freq;
    multiset<pair<int,int>> freq_order;
    
    void balance(){
        while(low.size()<high.size()){
            low.insert(*high.begin());
            high.erase(high.begin());
        }
        
        while(low.size()>high.size()+1){
            int x = *low.rbegin();
            high.insert(*low.rbegin());
            low.erase(low.find(x));
        }
    }
    
    
    void insert(int x){
        //mode
        sum+=x;
        cnt++;
       // variance
       sumSq+= x*x;
       // median 
       
       if(low.empty() ||  x<= *low.rbegin()) low.insert(x);
       else high.insert(x);
       
       balance();
       
       // mode 
       if(freq_order.find({freq[x],-x})!=freq_order.end()){
           freq_order.erase(freq_order.find({freq[x],-x}));
          
       }
       
       freq[x]++;
       
       freq_order.insert({freq[x],-x});
    }
    
    void remove(int x){
        // mean 
        sum-=x;
        cnt--;
        
        //variance
        sumSq-=x*x;
        
        // median
        if(high.find(x)!=high.end()){
            high.erase(high.find(x));
        }else if(low.find(x) != low.end()){
            low.erase(low.find(x));
        }
        
        // mode
        if(freq_order.find({freq[x],-x})!=freq_order.end()){
            freq_order.erase(freq_order.find({freq[x],-x}));
        }
        freq[x]--;
        if(freq[x]!=0) freq_order.insert({freq[x],-x});
        
        balance();
        
    }
    
    int mean(){
        
        
        return (sum*binPow(cnt,mod-2,mod))%mod;
        
    }
    
    int variance(){
        
        return (sumSq/cnt-mean()*mean());
        
        
    }
    
    int median(){
        if((low.size()+high.size())%2) return *low.rbegin();
        else{
            return ((low.rbegin()+*high.begin())(binPow(2,mod-2,mod)))%mod;
            
        }
    }
    
    int mode(){
        
        return -(freq_order.rbegin()->second);
        
    }
    
};

void solve(){
    int q;
    cin>>q;
    
    dashboard_data myDs;

    for(int i=0;i<q;i++){
        string type;
        cin>>type;
        if(type=="insert"){
            int x;
            cin>>x;
            myDs.insert(x);
            
            
        }else if(type=="getMean"){
             if (myDs.cnt==0) cout<<-1<<'\n';
            else {int ans = myDs.mean();
            cout<<(ans+mod)%mod<<'\n';
            }
            
        }else if(type=="getMedian"){
             if (myDs.cnt==0) cout<<-1<<'\n';
           else{ int ans = myDs.median();
            cout<<(ans+mod)%mod<<'\n';
           }
        }else if(type=="getMode"){
            if (myDs.cnt==0) cout<<-1<<'\n';
           else{ int ans = myDs.mode();
            cout<<ans<<'\n';
           }
            
        }else if(type=="remove"){
            int x;
            cin>>x;
            myDs.remove(x);
        }
        
    }
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}