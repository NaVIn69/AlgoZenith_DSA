#include <bits/stdc++.h>
using namespace std;

int minimum_stops(int target, int starting_bars, vector<int> dis_from_start, vector<int> energy_bars) {
    // Add the target as the last "station" with 0 energy bars
    dis_from_start.push_back(target);
    energy_bars.push_back(0);

    int n = dis_from_start.size();  // Number of charging stations (plus the target)
    priority_queue<int> max_heap;   // Max heap to store available energy bars from stations
    int stops = 0, current_position = 0, energy = starting_bars;

    for (int i = 0; i < n; i++  ) {
        int distance_to_next = dis_from_start[i] - current_position;

        // While we don't have enough energy to reach the next station
        while (energy < distance_to_next) {
            // If there are no more stations to recharge from, return -1 (can't reach target)
            if (max_heap.empty()) {
                return -1;
            }
            // Refill the battery using the station with the most energy bars
            energy += max_heap.top();
            max_heap.pop();
            stops++;  // One more stop
        }

        // Move to the next station
        energy -= distance_to_next;
        current_position = dis_from_start[i];

        // Add the current station's energy bars to the heap for future use
        max_heap.push(energy_bars[i]);
    }

    return stops;
}

int main() {
    // Example usage
    int target = 25;
    int starting_bars = 10;
    vector<int> dis_from_start = {10, 20, 15};  // distances of stations from start
    vector<int> energy_bars = {10, 5, 2};       // energy bars available at each station

    int result = minimum_stops(target, starting_bars, dis_from_start, energy_bars);

    if (result == -1) {
 cout << "Cannot reach the target" << endl;
    } else {
        cout << "Minimum number of stops: " << result << endl;
    }

}