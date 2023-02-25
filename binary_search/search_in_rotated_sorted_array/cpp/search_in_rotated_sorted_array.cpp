#include<iostream>
#include<vector>

using std::vector;

// Time O(log(n)) 
// Space O(1)

class Solution {
public:
    static int search(const vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        if(nums.size() == 1 && nums[0] == target) { return 0; }

        while(l <= r) {
            int m = (l + r) >> 1;
            if(nums[m] == target) return m;
            if(nums[l] <= nums[m]) {
                if(nums[l] <= target && target <= nums[m]) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            } else {
                if(nums[m] <= target && target <= nums[r]) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
        }

        return -1;
    }
};

int main() {
    std::vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 0;

    int answer = Solution::search(nums, target);

    std::cout << answer << '\n';

    return 0;
}
