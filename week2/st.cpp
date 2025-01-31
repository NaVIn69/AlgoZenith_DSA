#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="i am ninja";
    map<char ,int>mpp;
    for(auto v:s){
        cout<<v;
        mpp[v]++;
    }
}