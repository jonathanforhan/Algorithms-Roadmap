#include<iostream>
#include<vector>

using std::vector;

// Time O(log(n))
// Space O(1)

class Solution {
public:
    static int search(const vector<int>& nums, const int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high) {
            int mid = (high + low) >> 1;
            if(nums[mid] < target) {
                low = mid+1;
            } else if(nums[mid] > target) {
                high = mid-1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums = { -1, 0, 3, 5, 9, 12 };
    int target = 9;

    int answer = Solution::search(nums, target);
    std::cout << answer << '\n';
}
