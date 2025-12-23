#include<iostream>
using namespace std;
class student{
    static int totalstudent;
    public:
    int rollnumber;
    int age;
    student(){
        totalstudent++;
    }
    int getrollnumber(){
        return rollnumber;
    }
    // for accessing the private static data member 
    static int gettotalstudent(){
        return totalstudent;
    }
};
int student ::totalstudent=0;
int main(){
    student s1,s2,s3,s4,s5;
    cout<<student::gettotalstudent();
}