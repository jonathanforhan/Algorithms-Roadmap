#include<iostream>
#include<vector>
#include<string>
#include<functional>

using std::cout;
using std::vector;
using std::string;

template<typename T>
using fn = std::function<T>;

// Time O(2^n)
// Space O(n)

class Solution {
public:
    static vector<string> generateParenthesis(int n) {
        vector<string> answer = {};

        // start with a 1-char string "(" and add '(', ')' or both to generate
        // all possible solutions that still follow the parenthese rules
        fn<void(string, int, int)>genParen = [&](string _str, int _open, int _closed) {
            if(_closed == n && _closed == _open) {
                answer.push_back(_str);
                return;
            }
            if(_open < n)
                genParen(_str + '(', _open+1, _closed);
            if(_open > _closed)
                genParen(_str + ')', _open, _closed+1);
        };

        genParen("(", 1, 0); // "(", 1 open, 0 closed //

        return answer;
    }
};

int main() {
    int n = 10;

    auto answer = Solution::generateParenthesis(n);

    for(auto& n : answer) {
        cout << n << '\n';
    }
}
