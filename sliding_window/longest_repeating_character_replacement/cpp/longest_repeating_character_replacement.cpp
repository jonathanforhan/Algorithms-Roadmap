#include<iostream>
#include<string>

using std::string;

// Time O(n)
// Space O(1)

class Solution {
public:
    static int characterReplacement(const string& s, int k) {
        int index[26]{};
        int l = 0, r = 0;
        int max_char = 0;
        int best = 0;

        /* We keep char index with visited chars
         * the max is the maximizing char that does 
         * not get counted against k
         * we then compare the maximizer against the substring
         * and if > k, pop back. Since the max will set
         * the first time it's hit we only need simple if block
         * about twice as fast as while loop
         */
        while(r < s.size()) {
            index[s[r]-65]++;
            max_char = std::max(max_char, index[s[r]-65]);
            if(r - l + 1 - max_char > k) {
                index[s[l]-65]--;
                l++;
            }
            best = std::max(best, r - l + 1);
            r++;
        }
        return best;
    }
};

int main() {
    string s = "AABABBA";
    int k = 1;

    int answer = Solution::characterReplacement(s, k);
    std::cout << answer << '\n';

    return 0;
}
