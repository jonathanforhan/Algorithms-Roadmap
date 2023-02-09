#include<cctype>
#include<iostream>
#include<string>

using std::cout;
using std::string;

// Time O(n)
// Space O(1)

class Solution {
public:
    static bool isPalindrome(const string s) {
        int l = 0;
        int r = s.size()-1;

        while(l < r) {
            while(!std::isalnum(s[l]) && l < r) {
                l++;
            }
            while(!std::isalnum(s[r]) && l < r) {
                r--;
            }
            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++; r--;
        }

        return true;
    }
};

int main() {
    string s = "A man, a plan, a canal: Panama";

    bool answer = Solution::isPalindrome(s);

    cout << std::boolalpha << answer << '\n';
}
