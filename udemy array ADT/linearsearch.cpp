#include<iostream>
using namespace std;
bool ispresent(int arr[][4],int row,int column,int x){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(arr[i][j]==x){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int a[3][4]={{2,1,3,33},{11,22,333,44},{12,13,14,15}};
     bool smalloutput=ispresent(a,3,4,0);
     cout<<smalloutput<<endl;
}