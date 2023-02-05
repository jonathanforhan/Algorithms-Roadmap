#include<iostream>
#include<vector>
#include<unordered_map>

using std::cout;
using std::vector;
using std::unordered_map;

// Time O(n)
// Space O(n)

class Solution {
public:
    static vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++) {
            if(map.find(nums[i]) != map.end()) {
                return { i, map[nums[i]] };
            }
            map[target - nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> nums = { 2, 7, 11, 15 };

    auto answer = Solution::twoSum(nums, 9);

    for(auto& n : answer) {
        cout << n << ' ';
    }
    cout << '\n';
}
