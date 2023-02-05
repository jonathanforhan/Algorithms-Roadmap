#include<iostream>
#include<unordered_set>
#include<vector>

using std::vector;
using std::unordered_set;
using std::cout;

// Time O(n)
// Space O(n)

class Solution {
public:
    static bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for(auto& n : nums) {
            if(set.count(n))
                return true;

            set.insert(n);
        }
        return false;
    }
};

int main() {
    vector<int> nums = { 1, 2, 3, 1 };

    cout << std::boolalpha << Solution::containsDuplicate(nums) << '\n';
}
