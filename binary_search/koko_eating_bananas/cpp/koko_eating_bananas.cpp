#include<iostream>
#include<vector>

using std::vector;

// Time O(n * log(m))
// Space O(1)

class Solution {
public:
    static int minEatingSpeed(const vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        // high = greatest piles[i]
        for(auto& p : piles)
            high = std::max(p, high);
        int answer = high;

        while(low <= high) {
            long int hours = 0;
            int mid = (high + low) >> 1;
            for(auto& p : piles) {
                // add pile / i to hours total, round up with ternary,
                // cheaper than float conversion or something
                hours += p / mid;
                hours = p % mid == 0 ? hours : ++hours;
            }
            if(hours <= h) {
                // find minimum num of bananas needed while
                // forfilling time requirement
                // loop will end when the two pointers cross
                answer = std::min(answer, mid);
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return answer;
    }
};

int main() {
    vector<int> piles = { 30, 11, 23, 4, 20 };
    int h = 6;

    int answer = Solution::minEatingSpeed(piles, h);
    std::cout << answer << '\n';
}
