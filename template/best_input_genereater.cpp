#include <iostream>
#include<bits/stdc++.h>
#include <random>
#include <functional> // For std::bind()
using namespace std;
auto createUniformPseudoRandomNumberGenerator(double max)
{
 random_device seeder; 
 default_random_engine generator{seeder()};
 uniform_real_distribution<double> distribution{0.0, max};
 return bind(distribution, generator); 
}

int main() 
{

const int SIZE = 5;

int myArray[SIZE];


double limit{};
std::cout<<"Enter max number limit.\n";
std::cin>>limit;

static auto random_number=createUniformPseudoRandomNumberGenerator(limit);

for (size_t i{};i<SIZE;++i)
{
    myArray[i]= static_cast<int>(random_number());
}
for(int i=0;i<SIZE;i++){
    cout<<myArray[i]<<" ";
}
cout<<endl;


return 0;
}