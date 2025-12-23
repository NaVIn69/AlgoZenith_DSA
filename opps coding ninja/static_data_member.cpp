#include<iostream>
using namespace std;
class student{
    public:
    int rollnumber;
    int age;
    static int totalstudent;
    //we are making the constructor which is used for counting the total student;
    student(){
        totalstudent++;
    }
};
int student::totalstudent=0;
int main(){
    student s1;
    cout<<s1.rollnumber<<" "<<s1.age<<endl;
    //for accessing the static data member
    cout<<student::totalstudent<<endl;
}
