#include<iostream>
using namespace std;
int keypad(int nums,string output[]){
        if(nums==0){
            output[0]="";
            return 1;
        }
        int q=nums%10;
        int smalloutput=keypad(nums/10 , output);
    
        string s;
        if(q==2){
             s="abc";
        }
        else if(q==3){
             s="def";
        }else if(q==4){
             s="ghi";
        }
        for(int i=0;i<s.size();i++){
            for(int j=0;j<smalloutput;j++){
                output[j ]=output[j]+s[i];
            }
            cout<<endl;
            
        }
       return output->length(); 
}
int main(){
    int nums=23;
    string *output=new string[1000];
    int count=keypad(nums,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<" "<<endl;
    }
}