#include<iostream>
#include<vector>

using std::vector;

// Time O(n)
// Space O(1)

/* Simple sliding window,
 * always let r - l be optimal by setting l to lowest found
 */
class Solution {
public:
    static int maxProfit(const vector<int>& prices) {
        int l = 0, r = 1;
        int best = 0;

        while(r < prices.size()) {
            prices[r] > prices[l] ?
                best = std::max(best, prices[r] - prices[l]) :
                l = r;
            r++;
        }

        return best;
    }
};

int main() {
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };

    int answer = Solution::maxProfit(prices);

    std::cout << answer << '\n';

    return 0;
}
