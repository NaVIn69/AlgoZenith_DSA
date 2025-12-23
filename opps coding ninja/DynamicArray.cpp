#include<iostream>
using namespace std;
class DynamicArray{
int *data;
int nextindex;
int capacity;
public:
DynamicArray(){
    data=new int[5];
    nextindex=0;
    capacity=5;
}
void add(int element){
    if(nextindex==capacity){
      int *newdata=new int[2*capacity];
      for(int i=0;i<nextindex;i++){
        newdata[i]=data[i];
      }
      delete []data;
      data=newdata;
      capacity*=2;
    }  

    data[nextindex]=element;
    nextindex++;
}
int get(int i){
    if(i<nextindex){
        return data[i];
    }else{
        return -1;
    }
}
void add(int i,int element){
    if(i<nextindex){
        data[i]=element;
    }else if(i==nextindex){
        add(element);
    }else{
        return ;
    }
}
void print(){
    for(int i=0;i<nextindex;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
DynamicArray(DynamicArray const &d){
    //deep copy
    this->data=new int[d.capacity];
    for(int i=0;i<d.nextindex;i++){
        this->data[i]=d.data[i];
    }
    this->nextindex=d.nextindex;
    this->capacity=d.capacity;
}
void operator=(DynamicArray const &d){
     this->data=new int[d.capacity];
    for(int i=0;i<d.nextindex;i++){
        this->data[i]=d.data[i];
    }
    this->nextindex=d.nextindex;
    this->capacity=d.capacity;
}

};
int main(){
     DynamicArray d1;
     d1.add(10);
     d1.add(20);
     d1.add(30);
     d1.add(40);
     d1.add(50);
     d1.print();
     DynamicArray d2(d1);
     d2.print();
     d1.add(0,100);
     d2.print();
     d1.print();
}
