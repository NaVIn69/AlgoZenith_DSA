#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
class person{
 public:
 
   person(int age=0,string name="name is not given",string address="NA"){
    // here we have set parameter with their default value
       age_=age;
       name_=name;
       address_=address;
   }
//    void setname(string name){
//       name_=name;
//    }
//    void setage(int age){
//      age_=age;
//    }
   string getname(){
      return name_;
   }
   int getage(){
    return age_;
   }

   private:
    int age_;
    string name_;
    string address_;
};
void solve(){
    int n;
    cin>>n;
    person* p1 = new person(20,"pk","bihar");
    // person p2(10,"navin","daudnagar");
    person p2(10,"daudnagar");
   
    cout<<p2.getage()<<endl;
    cout<<p1->getage()<<endl;
    cout<<p2.getname()<<endl;
    
    delete p1;
    // int x=5;
    // int*a=&x;
    // cout<<(*a)<<endl;
    // cout<<(a)<<endl;
    

}
int main(){
    solve();
}