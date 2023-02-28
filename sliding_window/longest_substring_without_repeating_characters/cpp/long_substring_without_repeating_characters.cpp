#include<iostream>
#include<string>
#include<unordered_set>

using std::string;

// Time O(n)
// Space O(n)

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int best = 0;
        std::unordered_set<char> set;
        
        // expand window if unique
        // shrink window if duplicate
        while(r < s.size()) {
            while(set.count(s[r])) {
                set.erase(s[l]);
                l++;
            }
            best = std::max(best, r - l + 1);
            set.insert(s[r]);
            r++;
        }
        return best;
    }
};

int main() {
    string s = "abcabcbb";

    int answer = Solution::lengthOfLongestSubstring(s);
    std::cout << answer << '\n';

    return 0;
}
