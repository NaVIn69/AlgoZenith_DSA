#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> prefix_min(n), suffix_max(n);
    prefix_min[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix_min[i] = min(prefix_min[i-1], a[i]);

    suffix_max[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--)
        suffix_max[i] = max(suffix_max[i+1], a[i]);


    for(int i=0;i<n;i++){
        cout<<prefix_min[i]<<" ";
    } 
    cout<<endl;   
    for(int i=0;i<n;i++){
        cout<<suffix_max[i]<<" ";
    }  

    string ans;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        // All on left >= a[i]
        if (i > 0 && prefix_min[i-1] < a[i]) ok = false;
        // All on right <= a[i]
        if (i < n-1 && suffix_max[i+1] > a[i]) ok = false;
        ans.push_back(ok ? '1' : '0');
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}



int is_prime[1000100];
int spf[1000100];
void sieve(int maxi){
    for(int i=2;i<=maxi;i++){
        is_prime[i]=1;
    }
    for(int i=2;i<=maxi;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=maxi;j+=i){
                is_prime[j]=0;
            }
        }
    }
    for(int i=2;i<=maxi;i++){
        spf[i]=i;
    }
    for(int i=2;i<=maxi;i++){
         if(is_prime[i]){
            for(int j=2*i;j<=maxi;j+=i){
                spf[j]=i;
            }
         }
    }
}
vector<int>prime_fact(int n){
     vector<int>ans;
       while(n>1){
           ans.push_back(spf[n]);
           n/=spf[n];
       }
       return ans;
}

void solve2(){
   int n,m;
   cin>>n>>m;
//    sieve(m+2);
   int arr[n];
   int maxi=0;
   set<int>st;
   for(int i=0;i<n;i++){
         cin>>arr[i];
         maxi=max(arr[i],maxi);
   }
   int na=max(maxi,m);
   sieve(na);
   for(int i=0;i<n;i++){
    if(arr[i]==1)continue;
    vector<int>ans=prime_fact(arr[i]);
    for(auto x:ans){
        st.insert(x);
    }

   }
   vector<int>ans(m+1,1);
   for(int x:st){
       for(int k=x;k<=m;k+=x){
           ans[k]=0;
       }
   }
   int cnt=0;
   vector<int>t;
     for(int i=1;i<=m;i++){
           if(ans[i]==1){
            t.push_back(i);
             cnt++;
           }
     }
     
     cout<<cnt<<endl;
     for(auto p:t){
         cout<<p<<endl;
     }
     cout<<endl; 

}



int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
int lcm(int a,int b){
    int g=gcd(a,b);
    return (a*b)/g;
}
void solve3(){
    int n;
    cin>>n;
    vector<int>arr(n),prefix_gcd(n),suffix_gcd(n);
    for(int i=0;i<n;i++){
         cin>>arr[i];
         prefix_gcd[i]=arr[i];
         if(i){
          prefix_gcd[i]=gcd(prefix_gcd[i],prefix_gcd[i-1]);
         }
    }
    suffix_gcd[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix_gcd[i]=gcd(suffix_gcd[i+1],arr[i]);
    }
    vector<int>g;
    
    for(int i=0;i<n;i++ ){
         if(i==0){
            g.push_back(arr[i]*suffix_gcd[i+1]);
         }else if(i==n-1){
            g.push_back(arr[i]*prefix_gcd[i-1]);
         }else{
             int g_without_i=gcd(prefix_gcd[i-1],suffix_gcd[i+1]);
             int l=lcm(g_without_i,arr[i]);
             g.push_back(l);
         }

    }
    int ans=gcd(g[0],g[1]);
    for(int i=1;i<g.size();i++){
        ans=gcd(ans,g[i]);
    }
    cout<<ans<<endl;


}
