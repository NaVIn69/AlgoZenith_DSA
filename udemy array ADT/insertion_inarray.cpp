#include<iostream>
using namespace std;
struct array
{
 
    /* data */
    int A[10];
    int size;
    int length;
};
void display(struct array arr){
    cout<<"element are"<<endl;
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
}
void append(struct array *arr,int x){
    if(arr->length<arr->size){
        arr->A[arr->length++]=x;

    }
}
void insert(struct array *arr,int index,int x){
    if(index>=0&&index<=arr->length){
        for(int i=arr->length;i<index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
    }
}
int main(){
    struct array input={{8,3,7,12,15},10,5};
    append(&input,10);
    display(input);
    insert(&input,0,111);
    insert(&input,4,19);
    display(input);
    insert(&input,-2,6);
    display(input);
    insert(&input,9,23);
    display(input);

}