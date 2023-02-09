#include<iostream>
#include<vector>

using std::cout;
using std::vector;

// Time O(n)
// Space O(1)

class Solution {
public:
    static vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;

        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if(sum < target) {
                l++;
            } else if(sum > target) {
                r--;
            } else {
                return { l+1, r+1 };
            }
        }
        return {};
    }
};

int main() {
    vector<int> numbers = { 2, 7, 11, 15 };
    int target = 9;

    auto answer = Solution::twoSum(numbers, target);

    for(auto& n : answer) {
        cout << n << ' ';
    }
    cout << '\n';
}
