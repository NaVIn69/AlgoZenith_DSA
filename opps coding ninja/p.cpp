#include<iostream>
using namespace std;
class student{
public:
int rollno;
int age;
student(){
    cout<<"constructor"<<endl;
}
void display(){
    cout<<rollno<<" "<<age;
}

};
int main(){
    student s1;
}