#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Structure to represent a package
struct Package {
    int weight;
    string destination;
};

// Function to find the minimum number of trips and optimize loading
void optimizeShipping(vector<Package>& packages, int truckCapacity) {
    int n = packages.size();
    
    // Create a dynamic programming table to store the minimum trips
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        int currentWeight = 0;
        
        for (int j = i; j > 0; j--) {
            currentWeight += packages[j - 1].weight;
            
            if (currentWeight <= truckCapacity) {
                int trips = dp[j - 1] + 1;
                if (trips < dp[i]) {
                    dp[i] = trips;
                }
            } else {
                break; // No need to consider more packages
            }
        }
    }
    
    // Reconstruct the optimal loading of trucks
    vector<int> loading(n, 0);
    int i = n;
    while (i > 0) {
        int currentWeight = 0;
        int j = i;
        while (j > 0) {
            currentWeight += packages[j - 1].weight;
            if (currentWeight <= truckCapacity) {
                loading[j - 1] = i;
            } else {
                break;
            }
            j--;
        }
        i = j;
    }
    
    // Output results
    cout << "Minimum trips required: " << dp[n] << endl;
    cout << "Optimal loading of trucks:" << endl;
    int truckNumber = 1;
    for (int i = 0; i < n; i++) {
        if (loading[i] == i + 1) {
            cout << "Truck " << truckNumber << ": ";
            truckNumber++;
        }
        cout << packages[i].destination << " ";
    }
}

int main() {
    vector<Package> packages = {
        {10, "Destination A"},
        {20, "Destination B"},
        {15, "Destination A"},
        {25, "Destination C"},
        {30, "Destination B"}
    };
    int truckCapacity = 50;

    optimizeShipping(packages, truckCapacity);

    return 0;
}
