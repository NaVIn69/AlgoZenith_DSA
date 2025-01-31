#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Mex {

    map<int, int> frequency;
    set<int> missing_numbers;
    vector<int> A;

public:
    Mex(vector<int> & A) : A(A) {
        for (int i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (int x : A) {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }

    int mex() {
        return *missing_numbers.begin();
    }

    void update(int idx, int new_value) {
        if (--frequency[A[idx]] == 0)
            missing_numbers.insert(A[idx]);
        A[idx] = new_value;
        ++frequency[new_value];
        missing_numbers.erase(new_value);
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
     Mex mex1(a);
     cout<<mex1.mex()<<endl;
     int q;
     cin>>q;
     while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int pos,val;
            cin>>pos>>val;
            pos--;
            mex1.update(pos,val);
        }else{
            cout<<mex1.mex()<<endl;
        }
     }




}

signed main(){
    int t=1;
    // cin>>t;
    while(t--){
    solve();
    }
}