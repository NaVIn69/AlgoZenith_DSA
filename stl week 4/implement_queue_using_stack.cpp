#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct implemet_queue_using_stack{
    stack<int>input,output;
    void push(int x){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
        // tc -> O(n)'
    }
    int getfront(){
        if(input.empty()){
            return -1e9;
        }
        return input.top();
    }
   void pop_ele(){
        if(input.empty()){
            return ;
        }
      input.pop();
   }

};
// tc ->o(n)

struct queue_implementation{
    stack<int>input,output;
    void push(int x){
         output.push(x);
    }

    int getfront(){
        if(!input.empty()){
            return input.top();
        }else{
            while(!output.empty()){
                input.push(output.top());
                output.pop();
            }
            return input.top();
        }

    }
    void pop_ele(){
        if(!input.empty()){
            input.pop();
        }else{
             while(!output.empty()){
                input.push(output.top());
                output.pop();
            }
            input.pop();

        }
    }

};
void solve(){

}
signed main(){
    solve();
}