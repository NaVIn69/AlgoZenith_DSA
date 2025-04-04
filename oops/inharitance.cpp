#include<bits/stdc++.h>
using namespace std;

class person{
    public:
    // person(int age,string name){
    //    age_=age;
    //    name_=name;
    // }
    person(int age,string name) : age_(age) ,name_(name) {}
     // here we assign the value in constructor using list intializer

    int getage(){
        return age_;
    }
    private:
    int age_;
    string name_;
};

// here employee is drived class of the base class person 
 class employee:public person{
    public:
    employee(int id,string company,string name,int age) : person(age,name),company_(company),id_(id) {}

    private:
    int id_;
    string company_;
 };
int main(){
    employee e1(1,"google","navin",24);
    cout<<e1.getage()<<endl;

}