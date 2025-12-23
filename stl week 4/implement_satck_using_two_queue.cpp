#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int arr[100100];
int n;
// here q1 is acting as the stack
// here we have been implementing the stack using two queue
struct stack_double{
   queue<int>q1,q2;
   void push(int x){
      q2.push(x);
      while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
      }
      swap(q1,q2);
   }
   void pop(){
    q1.pop();
   }
   int top(){
       return q1.front();
   } 

};

// here we are implementing the stack using single queue;
struct stack_single{
     queue<int>q1;
     void push(int x){
        int sz=q1.size();
        q1.push(x);
        while(sz!=1){
            q1.push(q1.front());
            q1.pop();
            sz--;
        }
     }
     int top(){
        return q1.front();
     }
     void pop(){
        q1.pop();
     }

};
 

void reverse_stack(stack<int>&st){
    //base case
    if(st.empty()) return;
    //
    int num=st.top();
    st.pop();
    reverse_stack(st);
    st.push(num);
}
struct stack_usingarray{
    int top;
    void init(){
         top=-1;
    }
  
    void push(int x){
        top=top+1;
        arr[top]=x;
    }
    int top2(){
        return arr[top];
    }
    int pop(){
        top=top-1;
    }
};
void solve(){
cin>>n; 
stack<int>st;
for(int i=0;i<n;i++){
    cin>>arr[i];
    st.push(arr[i]);
}
reverse_stack(st);
while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}

 
// stack_usingarray st;
// int q;
// cin>>q;
// st.init();
// while(q--){
//     int op;
//     cin>>op;
//     if(op==0){
//         //push
//     int x;
//     cin>>x;
//     st.push(x);

//     }else if(op==1){
//         // pop();
//       int idx=st.top;
//       if(idx!=-1){
//         st.top=st.top-1;
//       }
//     }else{
//         //top
//         cout<<st.top2()<<endl;

//     }
// }


}
signed main(){
    solve();
}