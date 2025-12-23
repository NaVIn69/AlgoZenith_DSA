#include<iostream>
#include<string.h>
using namespace std;
class student{
    int age;
    public:
    char* name;
    //Deep copy 
    student(int age,char* name){
        this->age=age;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);   
    }
    void display(){
        cout<<age<<" "<<name<<endl;
    }
    //copy constructer
    student(student const &s){
     this->age=s.age;
     this->name=new char[strlen(s.name)+1];
     strcpy(this->name,s.name);
    }

};
int main(){
    char name[]="abcd";
    student s1(100,name);// deep copy  
    s1.display();
    student s2(s1);// inbuilt copy constructor is like shallow copy 
    s2.name[0]='x';
    s2.display();
    s1.display();

}