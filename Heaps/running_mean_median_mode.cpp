#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct running_mean_median_mode{
    int sum=0;
    int sumsq=0;
    int cnt=0;
    map<int,int>freq;
    multiset<int>low,high;
    multiset<pair<int,int>>freq_order; // here we are storing the {freq[x],x}

    void balanced(){
        if(low.size()<high.size()){
            int val=*high.begin();
            high.erase(high.find(val));
            low.insert(val);
        }else if(low.size()>high.size()+1){
            auto it=low.rbegin();
            int val=*it;
            low.erase(it);
            high.insert(val);
        }
    }

    void insert(int x){
        sum+=x;
        sumsq+=(x*x);
        cnt++;
        if(freq_order.find({freq[x],x})!=freq_order.end()){
            freq_order.erase(freq_order.find({freq[x],x}));
        }
        freq[x]++;
        freq_order.insert({freq[x],x});
        if(low.empty()) low.insert(x);
        else if(x<*low.rbegin()) low.insert(x);
        else high.insert(x);
        balanced();

    }
    void remove(int x){
        sum-=x;
        sumsq-=(x*x);
        cnt--;
        // for mode
         if(freq_order.find(make_pair(freq[x],x))!=freq_order.end()){
            freq_order.erase(freq_order.find(make_pair(freq[x],x)));
        }
        freq[x]--;
        freq_order.insert(make_pair(freq[x],x));
        // for median
        if(x<=*low.rbegin()){
            low.erase(low.find(x));
        }else{
            high.erase(high.find(x));
        }
        balanced();

    }

    double getVariance(){
        double ans=sumsq/cnt;
        double mean=get_mean();
        return ans-mean*mean;
    }

    double get_mean(){
        return sum/cnt;

    }

    double get_median(){
       if((low.size()+high.size())%2==0){
          return (*low.rbegin()+*high.begin())/2.0;
       }else{
           return (*low.rbegin())/1.0;
       }
    }
    int mode(){
        return freq_order.rbegin()->second;

    }
};

void solve(){

}
signed main(){

}