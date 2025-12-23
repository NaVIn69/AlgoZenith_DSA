#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n][3];
    for(int j=0;j<n;j++){
        for(int i=0;i<3;i++){
            cin>>a[i][j];
        }
    }
    int sum=0;
    for(int i=0;i<3;){
        for(int j=0;j<n;j++){
            sum+=a[j][i];
        }
        if(sum!=0){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}