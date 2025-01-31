// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // #define endl "\n"
// // int n,m;
// // vector<vector<int>>g;
// // vector<int>vis;
// // void solve(){
// //     // cin>>n>>m;
// //     // g.resize(n+1);
// //     // for(int i=0;i<m;i++){
// //     //     int a,b;
// //     //     cin>>a>>b;
// //     //     g[a].push_back(b);
// //     //     g[b].push_back(a);
// //     // }
// //     // vis.resize(n+1,0);
// //     string s="aaba";
// //     multimap<char,int>mpp;
// //     for(int i=0;s[i]!='\0';i++){
// //          mpp.insert(pair<char,int>(s[i],i));
// //     }
// //     for(auto v:mpp){
// //         cout<<v.first<<" "<<v.second<<endl;
// //     }

// // }
// // signed main(){
// //     ios_base::sync_with_stdio(NULL);
// //     cin.tie(NULL);
// //     cout.tie(NULL);
// //     int t=1;
// //    // cin>>t;
// //     while(t--){
// //         solve();
// //     }
// // }
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
// int n;
// vector<int> edge[100001];
// vector<int> backedge[100001];

// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     int m; cin >> n >> m;
//     int in_degree[n+1], dp[n+1];
//     for(int i = 0; i <= n; i++){
//         in_degree[i] = 0;
//         dp[i] = 0;
//     }
//     dp[1] = 1;
//     for(int i = 0; i < m; i++){
//         int a,b; cin >> a >> b;
//         edge[a].push_back(b);
//         backedge[b].push_back(a);
//         in_degree[b]++;
//     }
//     //uses Kahn's algorithm
//     queue<int> q;
//     for(int i = 1; i <= n; i++) {
//         if(in_degree[i] == 0) {
//             q.push(i);
//         }
//     }

//     while(!q.empty()) {
//         int node = q.front();
//         q.pop();
//         for(int next : edge[node]) {
//             in_degree[next]--;
//             if(in_degree[next] == 0) q.push(next);
//         }

//         for(int prev : backedge[node]) {
//             dp[node] = (dp[node] + dp[prev]) % 1000000007;
//         }
//     }
//     cout << dp[n] << endl;
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"
// int n,m;
// vector<vector<int>>g;
// vector<int>vis;
// void solve(){
//     // cin>>n>>m;
//     // g.resize(n+1);
//     // for(int i=0;i<m;i++){
//     //     int a,b;
//     //     cin>>a>>b;
//     //     g[a].push_back(b);
//     //     g[b].push_back(a);
//     // }
//     // vis.resize(n+1,0);
//     string s="aaba";
//     multimap<char,int>mpp;
//     for(int i=0;s[i]!='\0';i++){
//          mpp.insert(pair<char,int>(s[i],i));
//     }
//     for(auto v:mpp){
//         cout<<v.first<<" "<<v.second<<endl;
//     }

// }
// signed main(){
//     ios_base::sync_with_stdio(NULL);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t=1;
//    // cin>>t;
//     while(t--){
//         solve();
//     }
// }
#include<bits/stdc++.h>
using namespace std;

// Simple Debugging Template
#ifndef ONLINE_JUDGE
#define pr_arr(a,n)cout<<#a<<":";for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
#define pr_mat(mat,row,col)cout<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cout<<mat[i][j]<<" ";cout<<endl;}
#define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const set<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os, const stack<T>&s){os<<"[";stack<T> temp(s);while (!temp.empty()){os << temp.top();temp.pop();if (!temp.empty())os << ", ";}return os << "]";}
template<class T>ostream &operator<<(ostream &os, const queue<T>&q){os<<"[";queue<T>temp(q);int size=temp.size();for(int i=0;i<size;i++){T front=temp.front();os<<front;temp.pop();if(i<size-1)os<< ", ";temp.push(front);}return os<< "]";}
template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T> ostream &operator<<(ostream &os, const priority_queue<T>&pq){os<<"[";priority_queue<T> temp(pq);while(!temp.empty()){os<<temp.top();temp.pop();if(!temp.empty()){os<<", ";}}return os << "]";}
template<class S,class T>ostream &operator<<(ostream &os,const map<S,T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>void dbs(string str,T t){cout<<str<<":"<<t<<"\n";}
template<class T,class...S>void dbs(string str,T t,S... s){int idx=str.find(',');cout<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
template<class T>ostream &operator<<(ostream &os, const deque<T>&d){os<<"[";for(auto&it:d) os << it << " ";return os<<"]";}
#else
#define pr(...){}
#define debarr(a,n){}
#define debmat(mat,row,col){}
#endif
// Debugging Template ends
#define f                       first
#define s                       second
#define ARRAY_INPUT(arr, n)     for(int i = 0; i < n; i++) cin >> arr[i]
#define FOR(i, j, k, inc)       for (int i=j ; i<k ; i+=inc)
#define fr(i,x)                 for(int i = 0; i < x;i++)
#define mip(x)                  ll x;cin>>x
#define ip(x)                   cin>>x
#define pb                      push_back

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

using vi = vector<int>;
using vll = vector<long long>;
using vpii = vector<pii>;
using vpll = vector<pll>;

using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vvpii = vector<vector<pii>>;
using vvpll = vector<vector<pll>>;

using state = pll;

// 1 -> Right
// 2 -> Left
// 3 -> Down
// 4 -> Up


ll n,m;
vvll g;
vvll dis;

vi dx = {0,0,1,-1};
vi dy = {+1,-1,0,0};

void printer(deque<state> dq){
    cout << "dq:[ ";
    for(auto x: dq){
        cout << x.f << " " << x.s << " ";
    }
    cout << "]";
}

void bfs01(){
    dis.assign(n,vll(m,1e9));

    // Process the src node
    deque<state> dq;
    dq.pb({0,0});
    dis[0][0] = 0;

    pr(dis);
    pr(dq);

    while(!dq.empty()){
        // Process current node
        // 1. Visit
        auto node = dq.front();dq.pop_front();

        // 2. Process neighbours
        ll dir = g[node.f][node.s];
        ll cost = 0;
        for(int i = 0; i < 4; i++){
            ll x = node.f+dx[i];
            ll y = node.s+dy[i];
            // pr(x,y);
            if(x>=0 && x < n && y>=0 && y<m){
                if(dir-1 == i)cost = 0;
                else cost = 1;
                
                if(dis[x][y] > dis[node.f][node.s]+cost){
                    dis[x][y] = dis[node.f][node.s]+cost;
                    if(cost == 0) dq.push_front({x,y});
                    else dq.push_back({x,y});
                }
            }
        }
    }

}

void solve(){
    cin >> n >> m;
    g.resize(n);
    fr(i,n){
        g[i].resize(m);
        fr(j,m){
            cin >> g[i][j];
        }
    }
    pr(g);

    bfs01(); // Returns the shortest path to reach the S[n][m];
    pr(dis);
    cout << dis[n-1][m-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    freopen("Error.txt","w",stderr);
#endif


    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}