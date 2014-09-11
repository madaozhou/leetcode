#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        int numDecodings(string s) {
            int len = s.size();
            if (len == 0) return 0;
            if (s[0] == '0') return 0;
            vector<int> dp(len + 2, 1);
            for (int i = len - 1; i >= 0; i--) {
                if (s[i] == '0')
                    dp[i] = 0;
                else
                    dp[i] = dp[i + 1];
                if (i + 1 < len && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                    dp[i] += dp[i + 2];
                }
            }
        return dp[0];
        }
};

int main() {
    string s;
    Solution test;
    while (cin >> s && s != "quit") {
        cout << test.numDecodings(s) << endl;
    }

    return 0;
}
