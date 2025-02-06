#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Function implementation
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; // Position to place valid elements
        for (int num : nums) {
            if (i < 2 || num != nums[i - 2]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};

// Test function
void test() {
    Solution solution;
    
    // Example test case
    vector<int> nums = {1, 1, 1, 2, 2, 2, 2, 2, 3}; // Input array
    vector<int> expectedNums = {1, 1, 2, 2, 3}; // Expected output

    int k = solution.removeDuplicates(nums); // Call function
    nums.resize(k); // Resize nums to the new length
    
    // Verify length matches
    assert(k == expectedNums.size());

    // Verify elements match
    for (int i = 0; i < k; i++) {
        assert(nums[i] == expectedNums[i]);
         cout << "here is the output " << nums[i] << endl;
    }

    cout << "Test passed successfully!" << endl;
}

int main() {
    test();
    return 0;
}