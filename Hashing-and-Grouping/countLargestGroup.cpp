#include<vector>
#include<iostream>

using namespace std;

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
    