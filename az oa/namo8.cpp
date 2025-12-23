#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of generations to equalize layers
long findMinGeneration(int n, vector<long>& layer) {
    // Find the maximum number of neurons in any layer
    long maxNeurons = *max_element(layer.begin(), layer.end());
    long totalDiff = 0;

    // Calculate the total difference to the maximum layer size
    for (long neurons : layer) {
        totalDiff += maxNeurons - neurons;
    }

    // Now we handle the total difference by using alternating generations
    long generation = 1 ;

    // Process the differences
    while (totalDiff > 0) {
        if (generation % 2 == 0) {
            // Even generation: we can add 2 to one layer
            totalDiff -= 2;
        } else {
            // Odd generation: we can add 1 to one layer
            totalDiff -= 1;
        }
        
        generation++;  // Increment generation count

        // Make sure we don't go negative
        if (totalDiff < 0) {
            break;  // We have equalized layers
        }
    }

    return generation;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<long> layer(n);
    for (int i = 0; i < n; i++) {
        cin >> layer[i];
    }
    
    long result = findMinGeneration(n, layer);
    cout << result << "\n";
    
    return 0;
}

