#include<iostream>
using namespace std;
bool checkpalidrome(char arr[],int n){
int s=0;
int e=n-1;
while(s<=e){
    if(arr[s]==arr[e]){
        s++;
        e--;
    }
    else{
        return false;
    }
}
return true;
}
int main(){
    int n;
    cin>>n;
    char *input=new char[n];
    for(int i=0;i<n;i++){
cin>>input[i];
    }
    bool output=checkpalidrome(input,n);
    cout<<output<<endl;

}
