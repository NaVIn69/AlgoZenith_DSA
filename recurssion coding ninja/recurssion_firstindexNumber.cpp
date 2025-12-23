#include<iostream>
using namespace std;
int find(int arr[],int n,int x){
    int count=0;
    if(n==0){
        return -1;
    }
    if(arr[0]==x){
        return 0;
    }
    
    int smalloutput=find(arr+1,n-1,x);

    if(smalloutput==-1){
        return -1;
    }
    else{
        return smalloutput+1;
    }


}
int main(){
    int n,key;
    cin>>n>>key;
    int *input=new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int output=find(input,n,key);
    cout<<output<<endl;
}