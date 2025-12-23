#include<iostream>
using namespace std;
class fraction{
    private:
    int numerator;
    int denomerator;
    public:
    fraction(int numerator,int denomerator){
        this->numerator=numerator;
        this->denomerator=denomerator;
    }
    void print(){
        cout<<numerator<<"/"<<denomerator<<endl;
    }
    void simplify(){
        int gcd=1;
        int j=min(this->numerator,this->denomerator);
        for(int i=1;i<=j;i++){
            if(this->numerator%i==0&&this->denomerator%i==0){
                gcd=i;
            }
        }
        this->numerator=numerator/gcd;
        this->denomerator=denomerator/gcd;
    }
    fraction& operator++(){
        numerator=numerator+denomerator;
        simplify();
        return *this;
    }
};
int main(){
    fraction f1(10,2);
    ++f1;
    f1.print();
    ++(++f1);
    f1.print();
}