#include<bits/stdc++.h>
using namespace std;
struct median{
    multiset<int>low,high;
    void isbalanced(){
        // here 
        if(low.size()>high.size()+1){
           int k=*low.rbegin();
           low.erase(low.find(k));
           high.insert(k);
        }else if(low.size()<high.size()){
                int k=*high.begin();
                high.erase(high.find(k));
                low.insert(k);
        }


    }
    void insert(int x){
        if(low.empty()){
            low.insert(x);
        }else if(x<=*low.rbegin()){
            low.insert(x);
        }else{
            high.insert(x);
        }
        isbalanced();
    }
    void remove(int x){
        if(x>=*high.begin()){
            high.erase(high.find(x));
        }else{
            low.erase(low.find(x));
        }
    
    isbalanced();
}
};
