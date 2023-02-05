#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using std::cout;
using std::vector;

// Time O(n)
// Space O(n)

class Solution {
public:
    static vector<int> topKFrequent(const vector<int>& nums, int k) {
        std::unordered_map<int, int> map; // c++ maps are zero initialized
        std::map<int, vector<int>> top;   // ordered map of highest frequency nums
        vector<int> result = {};
    
        // rank num frequency O(n)
        for(const auto& n : nums) {
            map[n]++;
        }

        // order num frequency into vectors O(n)
        for(const auto& n : map) {
            top[n.second].push_back(n.first);
        }

        // reverse iterate to get highest frequency in O(k)
        for(auto rit = top.rbegin(); rit != top.rend(); ++rit) {
            for(auto& n : rit->second) {
                if(!k) break; k--;
                result.push_back(n);
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 1;

    auto result = Solution::topKFrequent(nums, k);

    for(auto& n : result) {
        cout << n << '\n';
    }
}
