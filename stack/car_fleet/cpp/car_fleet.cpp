#include<iostream>
#include<vector>
#include<queue>

using std::cout;
using std::vector;

// Time O(nlog(n))
// Space O(n)

class Solution {
public:
    static int carFleet(int target, const vector<int>& position, const vector<int>& speed) {
        // create a priority queue to queue the furthest car at top
        std::priority_queue<std::pair<int, int>> pq;
        for(int i = 0; i < speed.size(); i++) {
            pq.push({ position[i], speed[i] });
        }

        int answer = 0;
        while(!pq.empty()) {
            std::pair<int, int> a = pq.top();
            pq.pop();

            // time is the num of hours to reach target
            float time = (target - a.first) / static_cast<float>(a.second);

            while(!pq.empty()) {
                std::pair<int, int> b = pq.top();

                // is this example (10,2) and (8,4) reach target at same time
                // so both are popped and answer is incremented. Next (5,1)
                // and (3,3) are a and b. The time is takes for (5,1) to reach
                // target is 7 hours, but (3,3) will reach target by then so both are
                // popped and answer++. (0,1) is last man and will be the last car fleet
                if(b.first + (b.second * time) >= target) {
                    pq.pop();
                    continue;
                }
                break;
            }
            answer++;
        }

        return answer;
    }
};

int main() {
    vector<int> position = { 10, 8, 0, 5, 3 };
    vector<int> speed =    { 2,  4, 1, 1, 3 };
    int target = 12;

    int answer = Solution::carFleet(target, position, speed);

    cout << answer << '\n';
}
