#include<iostream>
using namespace std;
class fraction{
    private:
    int numenator;
    int denominator;
    public:
    fraction(int numenator,int denominator){
        this->numenator=numenator;
        this->denominator=denominator;
    }
    void print(){
        cout<<this->numenator<<"/"<<denominator<<endl;
    }
    void simplify(){
        int gcd=1;
        int j=min(this->numenator,this->denominator);
        for(int i=1;i<=j;i++){
            if(this->numenator%i == 0  &&  this->denominator%i == 0){
                gcd=i;
            }
        }
        this->numenator=this->numenator/gcd;
        this->denominator=this->denominator/gcd;
    }
    void add(fraction const &f2){
        int lcm=this->denominator*f2.denominator;
        int x=lcm/this->denominator;
        int y=lcm/f2.denominator;
        int num=x*this->numenator+(y*f2.numenator);
        numenator=num;
        denominator=lcm;
        simplify();
    }
    void multiply(fraction const &f2){
       this->numenator=numenator*f2.numenator;
        this->denominator=denominator*f2.denominator;
        simplify();
    }
 //   void print(){
   //     cout<<numenator<<"/"<<denominator<<endl;
   // }

};
int main(){
    fraction f1(10,4);
    fraction f2(20,5);
    f1.add(f2);
    f1.print();
    f2.print();
    f1.multiply(f2);
    f1.print();

}