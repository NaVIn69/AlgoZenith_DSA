#include<iostream>
using namespace std;
class student{
public:
int rollnumber;
private:
int age;
public:
~student(){
    cout<<"destorctor called :"<<endl;
}
student(){
    cout<<"default constructur"<<endl;
}
student(int rollnumber){
    cout<<"parameterized constructor 1 : "<<endl;
    this->rollnumber=rollnumber;
}
student(int a,int r){
    cout<<"parameterized constructor 2 : "<<endl;
    this->age=a;
    this->rollnumber=r;
}
void display(){
    cout<<age<<" "<<rollnumber<<endl;
}
};
int main(){
    student s1;//default constructor
    s1.display();
    cout<<endl;
    student s2(101);//parameterized constructor
    s2.display();
    cout<<endl;
    student s3(10,1001);//parameterized constructor
    s3.display();
    cout<<endl;
    student s4(s3);//copy constructor
    s4.display();
    cout<<endl;
    s1=s2;//copy assingment operator
    s1.display();
    cout<<endl;
    student s5=s4;// compiler treat as copy constructor not copy assigmnet constructor
      s5.display();
      cout<<endl;
      student *s6=new student(s3);
       (*s6).display();
       cout<<endl;
       student s7(*s6);
       (s7).display();
       delete s6;
}