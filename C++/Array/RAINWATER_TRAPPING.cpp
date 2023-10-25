#include <iostream>
#include <vector>

using namespace std;

int trap(const vector<int>& height) {
    int n = height.size();
    
    // Initialize leftMax and rightMax vectors
    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);
    
    // Compute leftMax
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i-1], height[i]);
    }
    
    // Compute rightMax
    rightMax[n-1] = height[n-1];
    for (int i = n-2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i+1], height[i]);
    }
    
    // Calculate trapped water at each index
    int trappedWater = 0;
    for (int i = 0; i < n; ++i) {
        trappedWater += min(leftMax[i], rightMax[i]) - height[i];
    }
    
    return trappedWater;
}

int main() {
    // Example usage:
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = trap(height);
    
    cout << result << endl;  // Output: 6
    
    return 0;
}
