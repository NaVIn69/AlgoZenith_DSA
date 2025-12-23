#include<iostream>
using namespace std;
class student{
public: 
int rollnumber;
private:
int age;
public:
void display(){
    cout<<rollnumber<<" "<<age<<endl;
}
student(){
    //defulat constructor
    
    cout<<"constructor called 1 "<<endl;
    cout<<"address "<<this<<endl;
}
//parameterized constructor
student(int a){
    cout<<"this : "<<this<<endl;
    cout<<"constructor called 2"<<endl;
    age=a;
   // cout<<age<<" "<<rollnumber<<endl;

}

};
int main(){
    student s1;
    s1.display();
    cout<<"address"<<" "<<&s1<<endl;;
    student s2(10);
    s2.display();
    student *s3=new student;
    s3->display();
    student *s4=new student(1023);
    s4->display();

}