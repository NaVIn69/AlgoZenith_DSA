#include<iostream>
using namespace std;
int main(){
int t;
	cin>>t;
	while(t--){
	   // int a[3][5]={1,3,5,7,9,2,4,6,8,11,12,
	   int x;
	   if(x>=1&&x<=10){
	       cout<<"Lower Double"<<endl; 
	   }else if(x>=11&&x<=15){
	       cout<<"Lower Single"<<endl;
	   }else if(x>=16&&x<=25){
	       cout<<"Upper Double"<<endl;
	   }else if(x>=25&&x<=30){
	       cout<<"Upper Single"<<endl;
	   }
	   
	}
	return 0;
}
