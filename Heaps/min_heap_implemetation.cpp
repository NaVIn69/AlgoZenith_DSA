#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct min_heap{
    vector<int>pq;
    min_heap(){

    }
    bool isempty(){
        return pq.size()==0;
    }
    int getsize(){
        return pq.size();
    }
    // uppify , here from downward , we move in the uppward direction ,
    // 
    void insert(int x){
        pq.push_back(x);
        int childindex=pq.size()-1; // here we have inserted the new element , here we have to maintain the cbt proprety of the tree
        while(childindex>0){
            int parentindex=(childindex-1)/2;
            if(pq[parentindex]>pq[childindex]){
                swap(pq[parentindex],pq[childindex]);
                childindex=parentindex;
            }else{
                break;
            }

        }
    }

    
    void remove(){
        if(isempty()) return ;
        if(pq.size()==1){
            pq.pop_back();
            return;
        }
        swap(pq[0],pq[pq.size()-1]);
        pq.pop_back();
        int parentindex=0;
        int leftchildindex=2*parentindex+1;
        int rightchildindex=2*parentindex+2;
        while(leftchildindex<pq.size()){
             int minindex=parentindex;
             // here we comparing with leftchildindex
           if(pq[leftchildindex]<pq[minindex]){
              minindex=leftchildindex;
              // rightchild index
           }else if(rightchildindex<pq.size()&&pq[rightchildindex]<pq[minindex]){
                  minindex=rightchildindex;
           }else{
                 break;
           }
             // here we are swapping the value and moving to their childindex 
           int temp=pq[minindex];
           swap(pq[parentindex],pq[minindex]);
           parentindex=minindex;
           leftchildindex=2*parentindex+1;
           rightchildindex=2*parentindex+2;
        }

    }

    int getmin(){
        if(isempty()){
            return -1e9;
        }
        return pq[0];
    }

};
void solve(){
  int n;
  cin>>n;
   min_heap m1;
  for(int i=0;i<n;i++){
    int c;
    cin>>c;
    m1.insert(c);
  }

  while(!m1.isempty()){
     cout<<m1.getmin()<<endl;
        m1.remove();
  }

}
signed main(){
    solve();
}