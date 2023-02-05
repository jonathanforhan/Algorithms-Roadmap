#include<iostream>
#include<string>
#include<stack>

using std::cout;
using std::string;

// Time O(n)
// Space O(n)

class Solution {
public:
    static bool isValid(string s) {
        std::stack<char> stack = {};

        // basic stack push and pop, uses ascii comaprison for validation
        for(const auto& c : s) {
            switch(c) {
                case '(': 
                case '{': 
                case '[': 
                    stack.push(c);
                    break;
                case ')': 
                case '}': 
                case ']': 
                    if(stack.empty()) return false;
                    if(stack.top() == c-2 || (stack.top() == c-1 && c == ')'))
                        stack.pop();
                    else
                        return false;
                    break;
                default:
                    break;
            }
        }
        return stack.size() == 0;
    }
};

int main() {
    string s = "()[]{}";

    bool result = Solution::isValid(s);
    cout << std::boolalpha << result << '\n';
}
