#include<iostream>
#include<vector>
#include<unordered_set>

using std::cout;
using std::vector;

// Time O(n)
// Space O(n)

class Solution {
public:
    static int longestConsecutive(const vector<int>& nums) {
        // convert vector to map with iterators
        std::unordered_set<int> set(nums.begin(), nums.end());
        int result = 0;
        
        for(auto n : set) {
            // if num has a smaller neighbor, skip.
            // This yeilds first iterator of given sequence
            if(set.count(n-1)) continue;

            int len = 1;
            // for every bigger neighbor incriment length of sequence
            while(set.count(++n)) {
                len++;
            }
            result = std::max(result, len);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    int result = Solution::longestConsecutive(nums);
    cout << result << '\n';
}
