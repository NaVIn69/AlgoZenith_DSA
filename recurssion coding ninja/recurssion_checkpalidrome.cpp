#include<iostream>
using namespace std;
bool checkPalindrome(char input[]) {
    // Write your code here
    static int count=0;
    if (input[0] != '\0') {
      count++;

      checkPalindrome(input + 1);
    }
    return count;
    
static int l=count-1;
static int s=0;
if(l==0||l==1){
    return true;
}
if(input[s]==input[l]){
    s++;
    l--;
}
else{
    return false;
}
checkPalindrome(input+1);
return true;
}
int main(){
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(checkPalindrome(arr)){
        cout<<"true";
    }else{
        cout<<"false";
    }
}



    
