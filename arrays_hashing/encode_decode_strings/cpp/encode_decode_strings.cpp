#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::vector;
using std::string;

// Time O(n)
// Space O(1)

class Solution {
public:
    static string encode(const vector<string> &strs) {
        string result = "";
        for(const auto& s : strs) {
            result.append(s);
            result.push_back(31); // ascii unit seperator
        }
        return result;
    }

    static vector<string> decode(string &str) {
        vector<string> result = {};
        string delimiter(1, 31);

        while(str.size() > 0) {
            result.push_back(str.substr(0, str.find(delimiter)));
            str.erase(0, str.find(delimiter) + delimiter.length());
        }
        return result;
    }
};

int main() {
    vector<string> strs = { "lint", "code", "love", "you" };

    string encode = Solution::encode(strs);
    cout << encode << "\n\n";

    auto decode = Solution::decode(encode);
    for(auto& n : decode) {
        cout << n << '\n';
    }
}
