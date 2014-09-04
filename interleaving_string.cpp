#include <string>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            int s1_len = s1.length();
            int s2_len = s2.length();
            int total_len = s3.length();
            if (total_len != s1_len + s2_len) return false;
            vector<vector<bool> > f(s1_len + 1, vector<bool>(s2_len + 1, false));
            f[0][0] = true;
            for (int i = 1; i <= s1_len; i++) {
                f[i][0] = f[i - 1][0] && (s3[i - 1] == s1[i - 1]);
            }
            for (int i = 1; i <= s2_len; i++) {
                f[0][i] = f[0][i - 1] && (s3[i - 1] == s2[i - 1]);
            }
            for (int i = 1; i <= s1_len; i++) {
                for (int j = 1; j <= s2_len; j++) {
                    f[i][j] = (f[i - 1][j] && (s3[i + j - 1] == s1[i - 1]))
                        || (f[i][j - 1] && (s3[i + j - 1] == s2[j - 1]));
                    /*
                     *printf("f[%d][%d] = %d  f[%d][%d] = %d\n",
                     *        i - 1, j, (int)f[i - 1][j], i, j - 1, (int)f[i][j - 1]);
                     *printf("s1:%c s2:%c s3:%c\n", s1[i - 1], s2[j - 1],
                     *        s3[i + j - 1]);
                     *printf("f[%d][%d] = %d\n", i, j, (int)f[i][j]);
                     *printf("========================\n");
                     */
                }
            }
            return f[s1_len][s2_len];
        }
};

int main() {
    string s1;
    string s2;
    string s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    Solution test;
    cout << test.isInterleave(s1, s2, s3) << endl;
    return 0;
}
