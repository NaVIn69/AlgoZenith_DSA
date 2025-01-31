#include<bits/stdc++.h>
using namespace std;
int main(){
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    // here we have taken the input;
    if(l1>r1 || l2>r2){
        // 
        cout<<"-1"<<endl;
        // this is my output for given input 
        // here i want to stop my code 
        // that why i return 0
        // why return 0?
        // bcz my main function is of data type int 
        return 0;
        // here we doing return 0 bcz here my code work is done 
        // return 0 ke krne ke badd ye main() function ke bhar aa jayega
        // return 

    }
    if(l2>r1 ||l1>r2){

        cout<<"-1"<<endl;
        // here we print our output 
        // i have done my task for that input
        // now i have to stop that code
        // that why i do return 0
        return 0;
    }
    int l=max(l1,l2);
    int r=min(r1,r2);
    cout<<l<<" "<<r<<endl;
}