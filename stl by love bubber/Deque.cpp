#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    for(int i:d){
        cout<<i<<" ";
    }
   /* cout<<endl;
    d.pop_front();
    for(int i:d){
        cout<<i<<" ";//1
    } */
    cout<<endl;
   // cout<<"first index -> "<<d.at(1)<<endl;
    cout<<"first index -> "<<d.at(0)<<endl;
    cout<<"front "<<d.front()<<endl;
    cout<<"empty or not"<<d.empty()<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<"after erase "<<d.size()<<endl;
    for(int i:d){
        cout<<i<<endl;        
    }




}