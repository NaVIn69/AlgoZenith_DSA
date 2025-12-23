#include<iostream>
using namespace std;
class fraction{
int numerator;
int denominator;
public:
fraction(int numerator,int denominator){
    this->numerator=numerator;
    this->denominator=denominator;
}
bool operator==(fraction const &f2){
    return(numerator==f2.numerator&&denominator==f2.denominator);

}

};
int main(){
    fraction f1(10,2);
    fraction f2(15,4);
    if(f1==f2){
        cout<<"equal"<<endl;
    }else{
        cout<<"not equal"<<endl;
    }
}