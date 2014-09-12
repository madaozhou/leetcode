#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define INF 100000

using namespace std;

class Solution {
    public:
        int minDistance(string word1, string word2) {
            int len1 = word1.size();
            int len2 = word2.size();
            vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, INF));
            dp[0][0] = 0;
            for (int i = 0; i <= len1; i++) {
                for (int j = 0; j <= len2; j++) {
                    if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    if (i > 0 && j > 0) {
                        if (word1[i - 1] != word2[j - 1]) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                        }
                        else {
                            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                        }
                    }
                }
            }
            return dp[len1][len2];
        }
};
