#include<iostream>
#include<utility>
#include<vector>
#include<stack>

using std::cout;
using std::vector;
using std::stack;
using std::pair;

// Time O(n)
// Space O(n)

class Solution {
public:
    static vector<int> dailyTemperatures(const vector<int>& temps) {
        vector<int> answer(temps.size(), 0);
        stack<pair<int, int>> stack;

        for(int i = 0; i < temps.size(); i++) {
            while(!stack.empty() && temps[i] > stack.top().first) {
                pair<int, int> top = stack.top();
                answer[top.second] = i - top.second;
                stack.pop();
            }
            stack.push(std::make_pair(temps[i], i));
        }

        return answer;
    }
};

int main() {
    vector<int> temps = { 73, 74, 75, 71, 69, 72, 76, 73 };

    auto answer = Solution::dailyTemperatures(temps);

    for(auto& n : answer) {
        cout << n << ' ';
    }
    cout << '\n';
}
