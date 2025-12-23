#include<bits/stdc++.h>
using namespace std;

class ISortingStartegy{
    public:
    virtual void sort(vector<int>&v)=0;
    virtual ~ISortingStartegy(){}
}

class BubbleSort : public ISortingStartegy{
   
    public:
    void sort(vector<int>&v):override{
         for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
            }
         }
    }

} 

class quikSort :public ISortingStartegy{
    public:
     void sort(vector<int>&v)override{
         cout<<"quick sort"<<endl;
     }
}

class SortContext{
    ISortingStartegy*startgey;

    public:
    SortContext(ISortingStartegy*s){
        this->startgey=s;
    }
    void setStartegy(ISortingStartegy*s){
        this->startgey=s;
    }
    void exec(){
        startgey->sort();
    }
}

int main(){
    vector<int>v={1,2,3,4,1,2};
  
    BubbleSort b;
    quikSort q;
    SortContext con(&b);
    con.exec();
    

}


