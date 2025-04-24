#include <iostream>
#include <cassert>
using namespace std;

// Include your class definition here
class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> groupCount;
            int maxSize = 0;

            // Calculate the sum of digits for each number and populate the groupCount map
            for (int i = 1; i <= n; ++i) {
                int sum = 0, num = i;
                while (num > 0) {
                    sum += num % 10;
                    num /= 10;
                }
                groupCount[sum]++;
                maxSize = max(maxSize, groupCount[sum]);
            }

            // Count the groups with the largest size
            int largestGroups = 0;
            for (auto& group : groupCount) {
                if (group.second == maxSize) {
                    largestGroups++;
                }
            }

            return largestGroups;
        }
};

int main() {
    Solution solution;

    // Test cases
    int test1 = solution.countLargestGroup(13); // Expected: 4
    int test2 = solution.countLargestGroup(2);  // Expected: 2
    int test3 = solution.countLargestGroup(24); // Try this out for practice
    int test4 = solution.countLargestGroup(1);  // Edge case, n = 1, expected: 1

    cout << "Test 1 (n = 13): " << test1 << endl; // Should print 4
    cout << "Test 2 (n = 2): " << test2 << endl;  // Should print 2
    cout << "Test 3 (n = 24): " << test3 << endl;
    cout << "Test 4 (n = 1): " << test4 << endl;  // Should print 1

    // Additional assertion checks for safety
    assert(test1 == 4);
    assert(test2 == 2);
    assert(test4 == 1);

    cout << "All tests passed!" << endl;

    return 0;
}
