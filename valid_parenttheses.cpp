#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int length = s.length();
        stack<char> brackets;
        for (int i = 0; i < length; i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                brackets.push(c);
            }
            else if (c == ')' || c == ']' || c == '}') {
                if (brackets.empty())
                    return false;
                else {
                    char tmp = brackets.top();
                    brackets.pop();
                    if (c == ')' && tmp == '(') continue;
                    if (c == ']' && tmp == '[') continue;
                    if (c == '}' && tmp == '{') continue;
                    return false;
                }
            }
        }
        return brackets.empty();
    }
};
