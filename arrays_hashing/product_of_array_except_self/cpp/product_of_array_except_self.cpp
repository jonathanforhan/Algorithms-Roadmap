#include<iostream>
#include<vector>

using std::cout;
using std::vector;

// Time O(n)
// Space O(1)

class Solution {
public:
    static vector<int> productExceptSelf(const vector<int>& nums) {
        vector<int> answer(nums.size(), 1);

        // multiply answer[i] by the product of all previous elements
        int prev = 1;
        for(int i = 0; i < nums.size(); i++) {
            answer[i] = prev;
            prev *= nums[i];
        }

        // multiply answer[i] by the product of all following elements
        int next = 1;
        for(int i = nums.size()-1; i >= 0; i--) {
            answer[i] *= next;
            next *= nums[i];
        }

        return answer;
    }
};

int main() {
    vector<int> nums = { 1, 2, 3, 4 };

    auto answer = Solution::productExceptSelf(nums);

    for(auto& n : answer) {
        cout << n << '\n';
    }
}
