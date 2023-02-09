#include<iostream>
#include<vector>

using std::vector;

// Time O(n)
// Space O(1)

class Solution {
public:
    static int maxArea(const vector<int>& height) {
        int answer = 0;
        int l = 0;
        int r = height.size()-1;

        while(l < r) {
            int h = std::min(height[l], height[r]);
            answer = std::max(answer, h * (r-l));

            height[l] > height[r] ? r-- : l++;
        }
        return answer;
    }
};

int main() {
    vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };

    int answer = Solution::maxArea(height);
    std::cout << answer << '\n';
}
