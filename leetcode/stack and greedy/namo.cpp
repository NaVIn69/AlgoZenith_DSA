#include <bits/stdc++.h>
using namespace std;
bool S(string str){
    bool check=false;

//    if((str[0]<='z'&&str[0]>='a')||(str[0]<='9'&&str[0]>=0)) return false;
    for(int i=1;i<str.size();i++){
        if(str[i]<='z' && str[i]>='a'){
            if(str[i-1]!='+'&&str[i+1]!='+'){
                cout<<str[i]<<endl;
                return false;
            }
        }
    }
    return true;
    

}

int main(){
    string str;
    cin>>str;
    cout<<S(str)<<endl;
}