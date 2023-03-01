#include<iostream>
#include<cstring>

using std::string;

// Time O(n)
// Space O(1)

class Solution {
public:
    static bool checkInclusion(const string s1, const string s2) {
        int index[26]{};
        int l = 0, r = 0;
        for(const auto& c : s1) {
            index[c-'a']++;
        }

        /* Average sliding window, uses ascii indexing
         * if conditions broken, increase l until condition 
         * is true again. match size to determine correctness
         * this size match is faster than the common loop check
         */
        while(r < s2.size()) {
            index[s2[r]-'a']--;
            while(index[s2[r]-'a'] < 0) {
                index[s2[l]-'a']++;
                l++;
            }
            if(r - l + 1 == s1.size()) {
                return true;
            }
            r++;
        }
        return false;
    }
};

int main() {
    string s1 = "abcdxabcde";
    string s2 = "abcdeabcdx";

    bool answer = Solution::checkInclusion(s1, s2);
    std::cout << std::boolalpha <<  answer << '\n';

    return 0;
}
