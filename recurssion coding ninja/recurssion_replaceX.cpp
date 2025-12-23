#include<iostream>
using namespace std;
int length(char input[]){
    int len=0;
    for(int i=0;input[i]!='\0';i++){
        len++;
    }
    return len;
}
void removeX(char input[],int start){
    if(input[0]=='\0'){
        return;
    }
    removeX(input,start+1);
    if(input[0]=='x'){
        int len=length(input);
        for(int i=0;i<len-1;i++){
            
            input[i]=input[i+1];
            
        }

    }
}
int main(){
    char input2[100];
    cin.getline(input2,100);
    removeX(input2,0);
    cout<<input2<<endl;
}