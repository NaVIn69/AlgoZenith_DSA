#include<bits/stdc++.h>
using namespace std;
void solve(){
int m,f,r;
    cin>>m>>f>>r;
    if(m==-1||f==-1){
cout<<"F"<<endl;
    }else if((m+f)>=80){
cout<<"A"<<endl;
    }else if((m+f)>=65&&(m+f)<80){
cout<<"B"<<endl;
}else if((m+f)>=50&&(m+f)<65){
    
      if(r>=80){
        cout<<"A"<<endl;
    }else if(r>=65){
        cout<<"B"<<endl;
    }else{
        cout<<"C"<<endl;
    }
    }else if((m+f)>=30&&(m+f)<50){
        if(r>=80){
        cout<<"A"<<endl;
    }else if(r>=65){
        cout<<"B"<<endl;
    }else if(r>=50){
        cout<<"C"<<endl;
    }else{
cout<<"D"<<endl;
    }
    }else if((m+f)<30){
        if(r>=80){
        cout<<"A"<<endl;
    }else if(r>=65){
        cout<<"B"<<endl;
    }else if(r>=50){
        cout<<"C"<<endl;
    }else if(r>=30){
cout<<"D"<<endl;
    }else{
cout<<"F"<<endl;
    }
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}