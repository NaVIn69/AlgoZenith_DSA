#include<bits/stdc++.h>
using namespace std;
int randBetween1()
{
    
    unsigned seed = time(0);
    srand(seed);
    
    const int MIN_VALUE = -100;
    const int MAX_VALUE = 100;
    
    return (rand() % (MAX_VALUE - MIN_VALUE + 1 )) + MIN_VALUE;
}
int randBetween2() {
  const int minValue = 0;
  const int maxValue = 10;

  // The keyword static is required now so that the PRNG and distribution
  // are not re-instantiated every time the function is called. This is
  // important for them both to work as intended. Re-instantiating resets
  // their state, and they constantly start from scratch. They must be allowed
  // to persist their state for better results.
  static std::mt19937 prng(std::random_device{}());  // Note the static
  static std::uniform_int_distribution<int> dist(minValue, maxValue);

  return dist(prng);
}



int main() {
   
    const int SIZE = 5;
    
    int arr[SIZE];
    for(int i=0;i<10;i++){
        arr[i]=randBetween2();
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    
    
    // ^^ how do I use function above to give myArray random values?
    
    return 0;
}