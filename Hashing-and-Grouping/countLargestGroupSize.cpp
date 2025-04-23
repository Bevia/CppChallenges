#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to calculate the sum of digits of a number
int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to return the number of groups with the largest size
int largestGroupSize(int n) {
    unordered_map<int, int> groupCount;
    int maxSize = 0;

    for (int i = 1; i <= n; ++i) {
        int sum = digitSum(i);
        groupCount[sum]++;
        maxSize = max(maxSize, groupCount[sum]);
    }

    int largestGroups = 0;
    for (auto& group : groupCount) {
        if (group.second == maxSize) {
            largestGroups++;
        }
    }

    return largestGroups;
}

int main() {
    int n = 13; // Change this value for testing
    cout << largestGroupSize(n) << endl;
    return 0;
}
