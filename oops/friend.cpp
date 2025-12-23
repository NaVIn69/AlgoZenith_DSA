#include<bits/stdc++.h>
using namespace std;

class B;

class student{
    private:
     string name_;
     int rollno_;
     string Address_;
    public:
      friend class B;
       student(string name,int rollno,string address){
           this->name_= name;
           this->rollno_= rollno;
           this->Address_= address;
       }
       void getname();
       friend void fn(student&s);
};

void student::getname(){
    cout<<this->name_<<endl;;
}

// here using the scope resolution we can implement the function outside of the class  after that function becomes non-inline 
void fn(student&s){
    // here this function can access the 
    cout<<s.name_<<endl;
}
// here class B is the friend of student class then he can access the private and protected memeber and 
class B{
    public:
    int id;
    void show(student&s){
        cout<<s.rollno_<<endl;
    }
};

int main(){
    student s1("navin",23,"daudnagar");
    s1.getname();
    fn(s1);
    B b1;
    b1.show(s1);
    
}