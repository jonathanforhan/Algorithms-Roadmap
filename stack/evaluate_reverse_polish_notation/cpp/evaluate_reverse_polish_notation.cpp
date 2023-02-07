#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include<stack>

using std::cout;
using std::vector;
using std::string;

// Time O(n)
// Space O(n)

class Solution {
public:
    static int evalRPN(const vector<string>& tokens) {
        std::stack<int> stack;

        for(const auto& s : tokens) {
            // I originally implimented with try catch(...)
            // the try catch was 8x slower, checking with isdigit
            // made it much faster 90ms to 11ms
            if(s.size() > 1 || std::isdigit(s[0])) {
                stack.push(std::stoi(s));
                continue;
            }
            char c = s[0];

            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            switch(c) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
                default:
                    throw std::invalid_argument("Must be operator or int");
            }
        }
        return stack.top();
    }
};

int main() {
    vector<string> tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };

    int answer = Solution::evalRPN(tokens);

    cout << answer << '\n';
}
