#include<bits/stdc++.h>
using namespace std;
void solve(){
pair<int,int>p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;
int x1,y1,x2,y2,x3,y3,x4,y4;
cin>>x1>>y1>>x2>>y2;
cin>>x3>>y3>>x4>>y4;
p10=make_pair(0,0);
p9=make_pair(0,0);
// first rectangle ka coordinate
p1=make_pair(x1,y1);
p2=make_pair(x2,y1);
p3=make_pair(x2,y2);
p4=make_pair(x1,y2);
// area of first rectangle
int l1=abs(x2-x1);
int b1=abs(y2-y1);
int a1=b1*l1;
// second rectangle ka coordinate
p5=make_pair(x3,y3);
p6=make_pair(x4,y3);
p7=make_pair(x4,y4);
p8=make_pair(x3,y4);
int a2=abs(x4-x3)*(y4-y3);
// find the coordinate of 2nd rectangle vertices in first rectangle
if(x3>=x1&&x3<=x2&&y3>=y1&&y3<=y2){
    p9=p5;
}else if(x4>=x1&&x4<=x2&&y3>=y1&&y3<=y2){
    p9=p6;
}else if(x4>=x1&&x4<=x2&&y4>=y1&&y4<=y2){
    p9=p7;
}else if(x3>=x1&&x3<=x2&&y4>=y1&&y4<=y2){
    p9=p8;
}
// find the coordinate of first  rectangle vertices in second rectangle
if(x1>=x3&&x1<=x4&&y1>=y3&&y1<=y4){
    p10=p1;
}else if(x2>=x3&&x2<=x4&&y1>=y3&&y1<=y4){
    p10=p2;
}else if(x2>=x3&&x2<=x4&&y2>=y3&&y2<=y4){
    p10=p3;
}else if(x1>=x3&&x1<=x4&&y2>=y3&&y2<=y4){
    p10=p4;
}
// find the area of rectangle 
//cout<<p10.first<<" "<<p10.second<<endl;
//cout<<p9.first<<" "<<p9.second<<endl;
p11=make_pair(p10.first,p9.second);
int l=abs(p11.second-p10.second);
int b=abs(p11.first-p9.first);
int area=a1+a2-b*l;
cout<<b*l<<" "<<area<<endl;






}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

}