#include<bits/stdc++.h>
using namespace std;
template<typename T,typename v>
class pair1{
    T x;
    v y;
    public:
    void setX(T x){
        this->x=x;
    }
    void setY(v y){
        this->y=y;
    }
    T getX(){
        return x;
    }
    v getY(){
        return y;
    }

};
int main(){
    pair1 <int,int> p;
    p.setX(10);
    p.setY(20);
    cout<<p.getX()<<" "<<p.getY()<<endl;
     pair1<int,pair1<int,int>>p2;
     p2.setX(30);
     p2.setY(p);
     cout<<p2.getX()<<" "<<p2.getY().getX()<<" "<<p2.getY().getY()<<endl;

}