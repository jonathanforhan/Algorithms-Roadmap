#include<iostream>
#include<vector>
#include<stack>

using std::cout;
using std::vector;

// Time O(n)
// Space O(n)

class Solution {
public:
    static int largestRectangleArea(const vector<int>& heights) {
        std::stack<std::pair<int, int>> stack;
        int answer = 0;

        // checks to area of the last biggest bar and return it's start
        auto checkStack = [&](int i) -> int {
            auto top = stack.top();
            int h = top.first;
            int w = i - top.second;
            int a = w * h;
            answer = std::max(answer, a);
            stack.pop();
            return top.second;
        };

        for(int i = 0; i < heights.size(); i++) {
            int start = i; // the start of the bar. Starts at i and gets changed to the prev 
                           // bar if the prev was bigger than current
            while(!stack.empty() && heights[i] < stack.top().first) {
                start = checkStack(i);
            }
            stack.push({ heights[i], start });
        }

        while(!stack.empty()) {
            checkStack(heights.size());
        }
        
        return answer;
    }
};

int main() {
    vector<int> heights = { 2, 1, 5, 6, 2, 3 };

    int answer = Solution::largestRectangleArea(heights);

    cout << answer << '\n';
}
