#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;

// Time O(n^2)
// Space O(n)

class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        int nums_size = nums.size() >= 3 ? nums.size() : 0; // skip if < 3

        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums_size-2 ; i++) {
            // if nums[i] > 0, l must also be so 0 sum is impossible
            if(nums[i] > 0)
                break;
            // if duplicate skip
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int l = i+1;
            int r = nums_size-1;

            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if(sum < 0) {
                    l++;
                } else if(sum > 0) {
                    r--;
                } else {
                    answer.push_back({ nums[r], nums[l], nums[i] });

                    // repeat until unique
                    do {
                        l++;
                    } while(l < r && nums[l-1] == nums[l]);

                    do {
                        r--;
                    } while(l < r && nums[r+1] == nums[r]);
                }
            }
        }
        return answer;
    }
};

int main() {
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };

    auto answer = Solution::threeSum(nums);

    for(auto& n : answer) {
        for(auto& m : n) {
            std::cout << m << ' '; 
        }
        std::cout << '\n';
    }
}
