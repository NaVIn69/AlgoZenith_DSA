#include<bits/stdc++.h>
using namespace std;
#define int long long

 int mod=1e9+7;
int n;
int a[1000001];
using pi=pair<int,int>;

//gcd of a and b ;; gcd(gcd(a,b),c)-> a b,c ka gcd

int gcd(int a,int b){
  
 if(a==0){
   return b;

 }
 return gcd(b%a,a);
    
}

// lcm of two number a,b

int lcm(int a,int b){
  return (a*b)/gcd(a,b);
}
// number is either prime or composite number
bool check_isprime(int n){

  for(int i=2;i*i<n;i++){

    if(n%i==0) return 0;

  }
  return 1;
}
// divisor of number n=d1*d2 d1 belongs to the (1,root(n)) and d2 belongs to the (root(n)+1,n) here first when we find the first diviosr then we also find the second the second divisor

vector<int> divisor(int n){
  vector<int>ans;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      ans.push_back(i);
      if(i*i!=n){
        ans.push_back(n/i);
      }
    }

  }
  return ans;
}


// prime factorisition of all number
vector<pi>prime_factorisation(int n){
  vector<pi>ans;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      int cnt=0;
      while(n%i==0){
        cnt++;
        n/=i;
      }
      ans.push_back({i,cnt});
    }
  }
  if(n>1){
    ans.push_back({n,1});
  }
  return ans;


}
// a^p%mod 
// iterative binay exponatiation
int binary_expontiation(int a,int b,int mod){

  int ans=1;

  while(b){
  
  if(b%2 == 1){
    ans=((a%mod)*(ans%mod)) %mod;
  }
  a= ((a%mod)*(a%mod))%mod;
  b/=2;

  }
  return ans;
}

// recursive binary exponatiaton
int binpow(int a,int p,int mod){

if(p==0) return 1%mod;

if(p%2) return (a%mod *binpow(a,p-1,mod))%mod;

else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;
}

}


// inverse binary_expontion
int inverse_binpow(int a,int b,int mod){
// a^-1%mod==

  return binpow(a,mod-2,mod);

}

// ncr 
int ncr(int n,int r){
  // o(r) if n is to big the o(r.log(n))
  int res=1;
for(int i=0;i<r;i++){

     res = (res * ((1LL)*(n-i)) % mod) % mod;

    res = (res*binpow(i+1,mod-2,mod))%mod;
   
    
  }
  res=(res%mod+mod)%mod;
  return res;
}
// x^y
int power(int x,int y){
  int res=1;
  while(y){
    if(y%2){
      res =((res%mod)*(x%mod))%mod;
    }
    x=((x%mod)*(x%mod))%mod;
    y=y/2;
  }
  return res%mod;
}

// factorial array
int fact[1000001];

void factorial(){
  fact[0]=1;
  fact[1]=1;

for(int i=2;i<1000001;i++){
  fact[i]=(fact[i-1]*i)%mod;
}

}
/// 1 D prefix sum
int prefix[1000001];
void pref(){
for(int i=0;i<1000001;i++){
  prefix[i]=a[i];

  if(i) prefix[i]+=prefix[i-1];
}

} 
// struct monotone deque to maintain the minimum of all element
struct monotone_deque{
  deque<int>dq;
  void insert(int x){
     while(!dq.empty()&&dq.back()>x){
        dq.pop_back();
     }
     dq.push_back(x);
  }
// erase
void erase(int x){
   if(dq.front()==x){
    dq.pop_front();
   }
}

// getmin value from deque
int getmin(){
  return dq.front();
}

};
// struct monotone deque to maintain maximum element
struct monotone_deque{
  deque<int>dq;
  void insert(int x){
     while(!dq.empty()&&dq.back()<x){
        dq.pop_back();
     }
     dq.push_back(x);
  }
// erase
void erase(int x){
   if(dq.front()==x){
    dq.pop_front();
   }
}

// getmin value from deque
int getmax(){
  return dq.front();
}

};
// for mean and mode 




struct myds{
    int sum=0;
    int sumsq=0;
    double cnt=0;
    map<int,int>freq;
    multiset<pair<int,int>>ferq_order;
    multiset<int>low,high;   
    void balanced(){
        while(low.size()<high.size()){
            int x=*high.begin();
            high.erase(high.find(x));
            low.insert(x);
        }
        while (low.size()>high.size()+1)
        {
            /* code */
            int x=*low.rbegin();
            low.erase(low.find(x));
            high.insert(x);

        }
        
        
    }
   
    void insert(int x){
        // for mean
        sum+=x;
        sumsq+=(x*x);
        cnt++;
        // for mode
        if(ferq_order.find(make_pair(freq[x],x))!=ferq_order.end()){
            ferq_order.erase(ferq_order.find(make_pair(freq[x],x)));
        }
        freq[x]++;
        ferq_order.insert(make_pair(freq[x],x));
       
       // for median
       if(low.empty()) low.insert(x);
       else if(x<=*low.rbegin()) low.insert(x);
       else high.insert(x);
        
    balanced();

    }
    void remove(int x){
        // for mean
        sum-=x;
        sumsq-=(x*x);
        cnt--;
        // for mode
         if(ferq_order.find(make_pair(freq[x],x))!=ferq_order.end()){
            ferq_order.erase(ferq_order.find(make_pair(freq[x],x)));
        }
        freq[x]--;
        ferq_order.insert(make_pair(freq[x],x));
        // for median
        if(x<=*low.rbegin()){
            low.erase(low.find(x));
        }else{
            high.erase(high.find(x));
        }
        balanced();

    }
    // mean
     double get_mean(){
       return sum/cnt;
     }
    
     /// variance 
     double get_variance(){
        double ans=sumsq/cnt;
        double mean=get_mean();
        return ans-mean*mean;
     }
  
  // meadin
     double get_median(){
        if((low.size()+high.size())%2){
            return *low.rbegin();
        }else{
            return (*low.rbegin()+*high.begin())/2.0;
        }
         

     }
     
// mode
     double get_mode(){
        return ferq_order.rbegin()->second;

     }

};









// for finding the index of subarray whoes sum is equal to x
void solve1(){
    int n,x;
    cin>>n>>x;
    int a[n];
    int p[n+1];
    p[0]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        
        
    }
    // this the first way to print the index of that subarray whoes sum is equal to x
    // by making the prefix sum with n+1 size;
    /*
    cout<<endl;
    /// here we made the prefix sum with n+1 size and starting value we have been keep the 0
    cout<<p[0]<<" ";
   for(int i=1;i<=n;i++){
    p[i]=p[i-1]+a[i-1];
    cout<<p[i]<<" ";
   }
   cout<<endl;
   // here we have to find the index of that subarry which sum is x
   map<int,vector<int>>mpp;
   for(int i=0;i<=n;i++){
    int find =p[i]-x;
    for(auto v:mpp[p[i]-x]){
        // here we have increse the index of prefix array by i here v  is l  
        // i-1 is r
        cout<<v<<" ,"<<i-1<<endl;
    }
    mpp[p[i]].push_back(i);

      
   }*/
   

  // 2nd method without incrase the size of prefix sum

   // here we make 
   // prefix sum
   for(int i=0;i<n;i++){
    if(i) a[i]+=a[i-1];
   }
   map<int,vector<int>>mpp;
   mpp[0].push_back(-1);
   for(int i=0;i<n;i++){
    // print the index when we find any l for our R
    for(auto v:mpp[a[i]-x]){
        cout<<v+1<<","<<i<<endl;
    }
    mpp[a[i]].push_back(i);

   }
   

}


  
void solve(){


}
signed main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
    int t=1;
     cin>>t;
     while(t--){
        solve();
     }
}