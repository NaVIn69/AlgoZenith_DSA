#include<iostream>
using namespace std;
struct array
{
    int A[10];
    int size;
    int length;
    /* data */
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
        arr[i]=arr[i-1];
    }
    arr->A[index]=x;
}
}
int Delete(struct array *arr,int index){
    int x=0;
    int i;
    if(index>=0&&index<=arr->length){
        x=arr->A[index];
        for(int i=index;i<arr->length-1;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}
int main(){
    struct array input={{2,3,4,5,6},10,5};
    cout<<Delete(&input,4)<<endl;
    display(input);
    cout<<endl;
    cout<<Delete(&input,7)<<endl;
display(input);
}

