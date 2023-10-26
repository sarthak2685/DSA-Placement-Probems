// https://leetcode.com/problems/peak-index-in-a-mountain-array/



#include <iostream>
#include <vector>

int peakIndexInMountainArray(std::vector<int>& arr) {
    int startIndex = 0;
    int endIndex = arr.size() - 1;

    while (startIndex < endIndex) {
        int middleIndex = startIndex + (endIndex - startIndex) / 2;
        if (arr[middleIndex] > arr[middleIndex + 1]) {
            endIndex = middleIndex;
        } else {
            startIndex = middleIndex + 1;
        }
    }
    return startIndex;
}

int main() {
    std::vector<int> arr = {-2, 0, 1, 2, 1, 0, -2};
    std::cout << peakIndexInMountainArray(arr) << std::endl;
    return 0;
}
