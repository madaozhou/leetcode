#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int t_length = T.length();
        int s_length = S.length();
        unordered_map<char, int> need_fill;
        unordered_map<char, int> has_found;
        string ret;
        for (int i = 0; i < t_length; i++) {
            if (need_fill.count(T[i]) == 0) {
                need_fill[T[i]] = 1;
            }
            else
                need_fill[T[i]]++;
            has_found[T[i]] = 0;
        }
        int win_length = s_length;
        int count = 0;
        for (int begin = 0, end = 0; end < s_length; end++) {
            char c = S[end];
            if (need_fill.count(c) > 0) {
                has_found[c]++;
                if (has_found[c] <= need_fill[c]) {
                    count++;
                }
            }
            if (count == t_length) {
                while (need_fill.count(S[begin]) == 0 ||
                        has_found[S[begin]] > need_fill[S[begin]]) {
                    if (need_fill.count(S[begin]))
                        has_found[S[begin]]--;
                    begin++;
                }
                if ((end - begin + 1) <= win_length) {
                    win_length = end - begin + 1;
                    ret = S.substr(begin, win_length);
                }
            }
        }
        return ret;
    }
};


int main() {
    string S;
    string T;
    Solution test;
    cin >> S;
    cin >> T;
    cout << test.minWindow(S, T) << endl;
    return 0;
}

