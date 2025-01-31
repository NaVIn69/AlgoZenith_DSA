#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct mobile_notification{
     int total_unread_msg;
     //for storing the first y msg   need queue
     queue<int>q;
     // for storing the total notification of x apllication which is read or unread
     map<int,pair<bool,int>>mpp;
     mobile_notification(){
        total_unread_msg=0;

     }
     void get_msg(int application){
        total_unread_msg++;
        mpp[application].second++;
        mpp[application].first=true;
        q.push(application);
     }
     void read_all(int application){
        if(mpp[application].first){
            total_unread_msg-=mpp[application].second;
            if(total_unread_msg<0){
                total_unread_msg=0;
            }

        }
        mpp[application].second=0;
        mpp[application].second=false;
     }
     int get_unread(int y){
        
        while(y>0){
            int first_application=q.front();
          //  q.pop();
            if(mpp[first_application].second<=y){
                q.pop();
         /**/   y-=mpp[first_application].second;
             
             if(mpp[first_application].first){
                
                total_unread_msg-=mpp[first_application].second;
                if(total_unread_msg<0){
                    total_unread_msg=0;
                }
                mpp[first_application].first=false;
             }
            }else{
                mpp[first_application].second-=y;
                mpp[first_application].first=true;
                y=0;
            }
            // y-=mpp[first_application].second;
           
        }
        return total_unread_msg;

     }
     int total_unread_msg_1(){
        return total_unread_msg;
     }



};

void solve(){
    int n,q;
    cin>>n>>q;
    mobile_notification mb;
    while(q--){
        int event,application;
        cin>>event>>application;
        if(event==1){
            mb.get_msg(application);
            cout<<mb.total_unread_msg_1()<<endl;
        }else if(event==2){
            mb.read_all(application);
            cout<<mb.total_unread_msg_1()<<endl;
        }else if(event==3){
          mb.get_unread(application);
          cout<<mb.total_unread_msg_1()<<endl;
        }
    }

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}