#include<iostream>
#include<math.h>
using namespace std;
int subs(string input,string output[]){
    if(input.empty()){
        output[0]="";
        return 1;
    }
    string smallstring=input.substr(1);
    int smalloutputsize=subs(smallstring,output);
    for(int i=0;i<smalloutputsize;i++){
        output[i+smalloutputsize]=input[0]+output[i];
    }
    return 2*smalloutputsize;

}
int main(){
    string input;
    cin>>input;
    int n=input.size();
    int output_size=pow(2,n);
    string* output=new string[output_size];
    int count=subs(input,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
}
