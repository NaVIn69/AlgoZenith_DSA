#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,p;
    cin>>n>>m>>p;
    int arr[n][m],brr[m][p],crr[n][p];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            cin>>brr[i][j];
        }
    }
    // here final matrix of n*p
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            int sum=0;
            // each arr[i][j] is goinf to multiple with each column of brr
            for(int k=0;k<m;k++){
                // traversing in the column of brr
                sum+=(arr[i][j]*brr[k][j]);
            }
            crr[i][j]=sum;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cout<<crr[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main(){
    solve();
}