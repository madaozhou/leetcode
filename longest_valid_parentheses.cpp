#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int  longestValidParentheses(string s) {
        int length = s.length();
        stack<int> brackets;
        int ret = 0;
        int last = -1;
        for (int i = 0; i < length; i++) {
            if (s[i] == '(') {
                brackets.push(i);
            }
            else {
                if (brackets.empty()) {
                    last = i;
                }
                else {
                    brackets.pop();
                    if (brackets.empty()) {
                        ret = max(ret, i - last);
                    }
                    else {
                        ret = max(ret, i - brackets.top());
                    }
                }
            }
        }
        return ret;
    }
};

int main () {
    string s;
    cin >> s;
    Solution test;
    cout << test.longestValidParentheses(s) << endl;

    return 0;
}
