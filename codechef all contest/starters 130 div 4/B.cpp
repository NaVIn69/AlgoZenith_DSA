#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
   int a,b;
   cin>>a>>b;
   int x=a;
   int y=b;
   int rev_x=0;
   if(x>y){
       cout<<"Yes"<<endl;
       continue;
   }
   while(x!=0){
       rev_x=rev_x*10+x%10;
       x=x/10;
   }
   int rev_y=0;
    while(y!=0){
       rev_y=rev_y*10+y%10;
       y=y/10;
   }
     if(a>rev_y||rev_x>b||rev_x>rev_y){
         cout<<"Yes"<<endl;
     }else{
         cout<<"NO"<<endl;
     }
	}
   
   
}
