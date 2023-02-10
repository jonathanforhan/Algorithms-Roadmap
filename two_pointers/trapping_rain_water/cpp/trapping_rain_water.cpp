#include<iostream>
#include<vector>

using std::vector;

// Time O(n)
// Space O(1)

class Solution {
public:
    static int trap(const vector<int>& height) {
        int l = 0;
        int r = height.size()-1;

        int l_max = height[l];
        int r_max = height[r];

        int answer = 0;

        // the two pointers converge to the maximum value in the array
        // allowing for the differnce of max to the floor to be added to
        // the answer each iteration
        while(l < r) {
            if(l_max < r_max) {
                l++;
                l_max = std::max(l_max, height[l]);
                answer += l_max - height[l];
            } else {
                r--;
                r_max = std::max(r_max, height[r]);
                answer += r_max - height[r];
            }
        }

        return answer;
    }
};

int main() {
    vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

    int answer = Solution::trap(height);
    std::cout << answer << '\n';
}
