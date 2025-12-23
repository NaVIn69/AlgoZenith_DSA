#include<iostream>
using namespace std;
struct Array
{
    /* data */
 int A[20];
 int size;
 int length;

};
void display(struct Array arr){
    cout<<"element are"<<endl;
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
}
int main(){
    struct Array a={{2,3,4,5,6},20,5};
    display(a);
    return 0;
}

