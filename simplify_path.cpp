#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size();
        if (len == 0)
            return "";
        stack<string> path_stack;
        int i = 0;
        while (i < len) {
            int begin = i;
            string tmp;
            while (i < len && path[i] != '/') {
                tmp.push_back(path[i]);
                i++;
            }
            if (begin != i) {
                if (tmp == "..") {
                    if (!path_stack.empty())
                        path_stack.pop();
                }
                else if (tmp != ".") {
                    path_stack.push(tmp);
                }
            }
            i++; // step over '/'
        }
        if (!path_stack.empty()) {
            string ret;
            for (int j = path_stack.size() - 1; j >= 0; j--) {
                ret.insert(0, "/" + path_stack.top());
                path_stack.pop();
            }
            return ret;
        }
        else
            return "/";
    }
};

int main () {
    string input;
    cin >> input;
    Solution test;
    cout << test.simplifyPath(input) << endl;
    return 0;
}
