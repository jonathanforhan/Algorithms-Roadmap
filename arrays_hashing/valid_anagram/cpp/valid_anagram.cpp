#include<iostream>
#include<string>

using std::cout;
using std::string;

// Time O(n)
// Space O(n)

class Solution {
public:
static bool isAnagram(string s, string t) {
    int index[256] = { 0 }; // initialize to zero

    if(s.size() != t.size()) return false;

    for(int i = 0; i < s.size(); i++) {
        index[s[i]]++;
        index[t[i]]--;
    }
    for(int i = 0; i < 256; i++) {
        if(index[i] != 0)
            return false;
    }
    return true;
}
};

int main() {
    string s = "anagram";
    string t = "nagaram";

    cout << std::boolalpha << Solution::isAnagram(s, t) << '\n';
}
