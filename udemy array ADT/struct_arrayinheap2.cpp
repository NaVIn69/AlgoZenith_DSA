#include<iostream>
using namespace std;
struct array
{
    /* data */
    int *A;
    int size;
    int length;
};
void display(struct array arr){
    cout<<"element are"<<endl;
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
}
int main(){
    struct array b;
    int n;
    cout<<"enter the size of an array";
    cin>>b.size;
    b.A=new int[b.size];
    b.length=0;
    cout<<"enter the number";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b.A[i];
    }
    b.length=n;
    display(b);
}
