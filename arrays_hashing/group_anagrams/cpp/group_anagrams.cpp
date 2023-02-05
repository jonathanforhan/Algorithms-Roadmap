#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using std::cout;
using std::vector;
using std::string;
using std::wstring;
using std::unordered_map;

// Time O(n * m) where m is string length
// Space O(n * m)

class Solution {
public:
    static vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        unordered_map<wstring, vector<string>> map;
        vector<vector<string>> result = {};

        // using unicode wstring to get greater bounds
        // while simplifying the indexing compared to hash
        for(const auto& str : strs) {
            wstring key(26, '\0');
            for(auto& c : str) {
                key[c - 'a']++;
            }
            map[key].push_back(str);
        }

        for(auto& n : map) {
            result.push_back(n.second);
        }

        return result;
    }
};

int main() {
    vector<string> strs = { "eat","tea","tan","ate","nat","bat" };

    auto answer = Solution::groupAnagrams(strs);

    for(auto& n : answer) {
        for(auto& m : n) {
            cout << m << ' ';
        }
        cout << '\n';
    }
}
