#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pod {
    int pods;
    int cost;
};

bool comparator(const Pod& a, const Pod& b) {
    return a.pods < b.pods;
}

long getMinCost(vector<int>& pods, vector<int>& cost) {
    int n=pods.size();
    vector<Pod> podList(n);
    
   
    for (int i = 0; i < n; i++) {
        podList[i] = {pods[i], cost[i]};
    }
    
    // Sort the podList by pod values
    sort(podList.begin(), podList.end(), comparator);
    
    long totalCost = 0;

    for (int i = 1; i < n; i++) {
      
        if (podList[i].pods <= podList[i - 1].pods) {
            int incrementNeeded = podList[i - 1].pods + 1 - podList[i].pods;
            totalCost += (long) incrementNeeded * podList[i].cost;
            podList[i].pods = podList[i - 1].pods + 1;
        }
    }
    
    return totalCost;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> pods(n), cost(n);
    
    for (int i = 0; i < n; i++) {
        cin >> pods[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    
    // Calculate and output the minimum cost
    cout << getMinCost(pods, cost) << endl;
    
    return 0;
}
