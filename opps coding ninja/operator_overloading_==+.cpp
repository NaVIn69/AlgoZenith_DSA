#include<iostream>
using namespace std;
class fraction{
private:
int denominater;
int nominater;
public:
void print(){
    cout<<this->nominater<<"/"<<this->denominater<<endl;
}
fraction(int nominater,int denominater){
    this->nominater=nominater;
    this->denominater=denominater;
}
void simplify(){
    int gcd=1;
    int j=min(this->nominater,this->denominater);
    for(int i=1;i<=j;i++){
        if(this->nominater%i==0&&this->denominater%i==0){
            gcd=i;
        }
    }
    this->nominater=this->nominater/gcd;
    this->denominater=this->denominater/gcd;
}
fraction operator+(fraction const &f2) const {
    int lcm=this->denominater*f2.denominater;
    int x=lcm/denominater;
    int y=lcm/f2.denominater;
    int num = x*this->nominater+y*f2.denominater;
fraction fnew(num,lcm);
fnew.simplify();
return fnew;
}
fraction operator*(fraction const &f2){
   this->nominater=nominater*f2.nominater;
    this->denominater=denominater*f2.denominater;
    fraction fnew(nominater,denominater);
    fnew.simplify();
    return fnew;
}
};
int main(){
    fraction f1(10,4);
    fraction f2(20,6);
    f1.print();
    fraction f3=f1+f2;
    fraction f4=f1*f2;
    f2.print();
    f3.print();
    f4.print();
}