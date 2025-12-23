#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
// here we have given a equation ax + by =c;
// find the one solution
// find all solution
// find the solution with minimum vlaue of x+y;

//.................................................
// this gcd give me the gcd of a,b and also give me the cofficient of x and y

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    // cout<<x<<" "<<y<<endl;
    return d;
}

// here we have been find the any solution of equation 
//ax + by = c;
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    // cout<<x0<<" "<<y0<<endl;
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}
vector<pair<int, int>> solutions;
int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);
    // cout<<c<<" "<<a<<" "<<b<<endl;
     a=a*g;
     b=b*g;
    if(lx<=rx){

    for (int k = 0; lx + k * (abs(b)/g) <= rx; k++) {
        int xk = lx + k * (abs(b)/g);
        int yk = (c - a * xk) / b;
        solutions.push_back({xk, yk});
    }

    // Printing all solutions
    for (auto sol : solutions) {
        cout << "x = " << sol.first << ", y = " << sol.second << endl;
    }
    }

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
//Once we have  
/*
$l_x$  and  
$r_x$ , it is also simple to enumerate through all the solutions. Just need to iterate through   x= l_x+k*(b/g)
 k>0 and until r_x=x
 
$x = l_x + k \cdot \frac{b}{g}$  for all  
$k \ge 0$  until  
$x = r_x$ , and find the corresponding  
$y$  values using the equation  
$a x + b y = c$ .
*/
void solve(){
    int a,b,c,g,x1,y1;
    cin>>a>>b>>c;
    int x_min=-1000;
  int  x_max=1000;
  int y_min=-1000;
  int y_max=1000;
   g=gcd(a,b,x1,y1);

       
       int ans=find_all_solutions(a,b,c,x_min,x_max,y_min,y_max);
       cout<<ans<<endl;
}
signed main(){
    solve();

}
