#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<string> path;
        helper(s, 0, path);
        return ret;
    }

private:
    vector<vector<string> > ret;
    void helper(string &s, int start, vector<string> &path) {
        if (s.length() == start) {
            ret.push_back(path);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                helper(s, i + 1, path);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int start, int end)
    {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    string input;
    cin >> input;
    vector<vector<string> > ret;
    Solution test;
    ret = test.partition(input);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
