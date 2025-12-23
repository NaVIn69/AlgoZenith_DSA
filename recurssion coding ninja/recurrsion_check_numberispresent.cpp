#include<iostream>
using namespace std;
bool check(int arr[],int n,int key){
    if(n==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    bool smallcheck=check(arr+1,n-1,key);

}
int main(){
    int n,x;
    cin>>n>>x;
    int *input=new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cout<<check(input,n,x)<<endl;
    
}