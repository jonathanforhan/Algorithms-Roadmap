#include<iostream>
#include<vector>

using std::vector;

// Time O(log(n))
// Space O(1)

class Solution {
public:
    static int findMin(const vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int answer = nums[high / 2];

        while(low <= high) {
            int mid = (low + high) >> 1;
            nums[high] > nums[mid] ? high = mid : low = mid+1;
            answer = std::min(answer, nums[mid]);
        }
        return answer;
    }
};

int main() {
    vector<int> nums = { 3, 4, 5, 1, 2 };

    int answer = Solution::findMin(nums);
    std::cout << answer << '\n';
}
