#include<iostream>
using namespace std;
class student{
 int age;
 char* name;
 public:
 //constructer
 student(int age,char* name){

    this->age=age;
    this->name=name;// shallow copy here ek me change karn se dusre m bhi dikhata hai bcz dono ka array ka address same plac pe show krta hai
 }
 void display(){
    cout<<age<<" "<<name<<endl;
 }
};
int main(){
    char name[]="abcd";
    student s1(102,name);
    s1.display();
    name[3]='e';
    student s2(105,name);
    s2.display();
    s1.display();

}