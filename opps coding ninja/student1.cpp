#include<iostream>
using namespace std;
//#include "student.cpp"
class student{
    public :
  int rollNumber;
  string name;
  private :
  int age;
  public :
  void display(){
    cout<<age<<" "<<rollNumber<<endl;
  }
  int getAge(){// by the help of this we can read the age
     return age;
  }
  void setAge(int a,int pass){
    if(pass!=123){
        return;
    }
    if(a<0){
        return ;
    }
    age=a;
  }
};
int main(){
    // statically object created;
    student s1;
    
   // s1.rollNumber=24;
    s1.name="navin";
    cout<<s1.rollNumber<<endl;
    cout<<s1.name<<endl;
    s1.setAge(24,123);
    cout<<"s1 age :"<<s1.getAge()<<endl;

    //dynamically object created;
    student*s2=new student;
    (*s2).rollNumber=27;
    cout<<((*s2).rollNumber)<<endl;
    s2->setAge(27,123);
    cout<<"s2 age :"<<s2->getAge()<<endl;
}


