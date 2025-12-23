#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
struct myds{
    int sum=0;
    int sumsq=0;
    double cnt=0;
    map<int,int>freq;
    multiset<pair<int,int>>ferq_order;
    multiset<int>low,high;   
    void balanced(){
        if(low.size()<high.size()){
            int x=*high.begin();
            high.erase(high.find(x));
            low.insert(x);
        }
        if (low.size()>high.size()+1)
        {
            /* code */
            int x=*low.rbegin();
            low.erase(low.find(x));
            high.insert(x);

        }
        
        
    }
   
    void insert(int x){
        // for mean
        sum+=x;
        sumsq+=(x*x);
        cnt++;
        // for mode
        if(ferq_order.find(make_pair(freq[x],x))!=ferq_order.end()){
            ferq_order.erase(ferq_order.find(make_pair(freq[x],x)));
        }
        freq[x]++;
        ferq_order.insert(make_pair(freq[x],x));
       
       // for median
       if(low.empty()) low.insert(x);
       else if(x<=*low.rbegin()) low.insert(x);
       else high.insert(x);
        
    balanced();

    }
    void remove(int x){
        // for mean
        sum-=x;
        sumsq-=(x*x);
        cnt--;
        // for mode
         if(ferq_order.find(make_pair(freq[x],x))!=ferq_order.end()){
            ferq_order.erase(ferq_order.find(make_pair(freq[x],x)));
        }
        freq[x]--;
        ferq_order.insert(make_pair(freq[x],x));
        // for median
        if(x<=*low.rbegin()){
            low.erase(low.find(x));
        }else{
            high.erase(high.find(x));
        }
        balanced();

    }
    // mean
     double get_mean(){
       return sum/cnt;
     }
    
     /// variance 
     double get_variance(){
        double ans=sumsq/cnt;
        double mean=get_mean();
        return ans-mean*mean;
     }
  
  // meadin
     double get_median(){
        if((low.size()+high.size())%2){
            return *low.rbegin();
        }else{
            return (*low.rbegin()+*high.begin())/2.0;
        }
         

     }
     
// mode
     double get_mode(){
        return ferq_order.rbegin()->second;

     }

};
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
   // cin>>t;
   myds m;
   m.insert(1);
   m.insert(1);
   m.insert(1);
   m.insert(1);
   m.insert(3);
   m.insert(2);
   cout<<m.get_mean()<<endl;
   cout<<m.get_median()<<endl;
   cout<<m.get_mode()<<endl;
   
}