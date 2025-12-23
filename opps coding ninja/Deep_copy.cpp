#include<iostream>
#include<string.h>
using namespace std;
class student{
int age;
public:
char* name;
student(int age,char* name){
    this->age=age;
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
}
void display(){
    cout<<age<<" "<<name<<endl;
}

};
int main(){
    char name[]="abcd";
    student s1(100,name);
    s1.display();
    name[3]='e';
    student s2(1002,name);
    s2.display();
    s1.display();
}