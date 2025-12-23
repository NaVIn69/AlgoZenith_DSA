#include<iostream>
using namespace std;
bool checkpalidrome(char input[]){
    static int count=0;
    if(input[0]!='\0'){
        count++;
    }
    checkpalidrome(input+1);
    static int l=count;
    static int s=0;
    if(s<=l){
        if(input[0]==input[l]){
            s++;
            l--;
        }
        else{
            return false;
        }

    }
    checkpalidrome(input+1);
    return true;
}
int main(){
    int n;
    cin>>n;
    char input[n];
    for(int i=0;i<n;i++){
        cin>>input[n];
    }
    if(checkpalidrome(input)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}