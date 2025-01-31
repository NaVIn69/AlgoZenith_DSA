#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int binpow(int a,int p,int mod){

if(p==0) return 1%mod;

if(p%2) return (a%mod *binpow(a,p-1,mod))%mod;

else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;
}

}
void solve(){
   // string v;
    //cin>>v;
    char brac;
   int a,b,c,p;
   cin>>brac;
   char op1,op2;
   cin>>a>>op1>>b>>op2>>c;
   char brac2;
   cin>>brac2;
   string mods;
   cin>>mods;
   cin>>p;
  
  if(op1=='/'){
    int mini_ans=(a*binpow(b,p-2,p))%p;
    if(op2=='*'){
    int ans=(mini_ans%p*(c%p))%p;
    cout<<(ans%p+p)%p<<endl;
    }else if(op2=='+'){
        int ans=(mini_ans%p+c%p)%p;
        cout<<(ans%p+p)%p<<endl;
    }else if(op2=='-'){
        int ans=(mini_ans%p-c%p)%p;
        cout<<(ans%p+p)%p<<endl;
    }else{
        int ans=(mini_ans*binpow(c,p-2,p))%p;
        cout<<(ans%p+p)%p<<endl;
    }
}else if(op1=='*'){
    if(op2=='/'){
        int mini_ans=(b%p*binpow(c,p-2,p))%p;
        int ans=(a%p*mini_ans%p)%p;
        cout<<(ans%p+p)%p<<endl;
    }else{
        int mini_ans=(a%p*(b%p))%p;
        if(op2=='+'){
        int ans=(c%p+mini_ans%p)%p;
        cout<<(ans%p+p)%p<<endl;
        }else if(op2=='-'){
            int ans=(mini_ans%p-c%p)%p;
            cout<<(ans%p+p)%p<<endl;
        }else if(op2=='*'){
            int ans=(mini_ans*c%p)%p;
            cout<<(ans%p+p)%p<<endl;
        }
    }
} else if(op1=='+'||op1=='-'){
      if(op2=='/'){
         int mini_ans=(b%p*binpow(c,p-2,p))%p;
         if(op1=='+'){
           int ans=(a%p+mini_ans%p)%p;
           cout<<(ans%p+p)%p<<endl;
         }else{
            int ans=(a%p-mini_ans%p)%p;
            cout<<(ans%p+p)%p<<endl;
         }
      }else if(op2=='*'){
        int mini_ans=(b%p*c%p)%p;
        if(op1=='+'){
            int ans=(a%p+mini_ans%p)%p;
            cout<<(ans%p+p)%p<<endl;
        }else{
            int ans=(a%p-mini_ans%p)%p;
            cout<<(ans%p+p)%p<<endl;
        }
      }else if(op2=='+'||op2=='-'){
        int mini_ans=0;
            if(op1=='+'){
             mini_ans=(a%p+b%p)%p;
            }else{
                mini_ans=(a%p-b%p)%p;
            }
            if(op2=='+'){
                int ans=(mini_ans+c%p)%p;
                cout<<(ans%p+p)%p<<endl;
            }else if(op2=='-'){
                int ans=(mini_ans-c)%p;
                cout<<(ans%p+p)%p<<endl;
            }
        
      }
}
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}