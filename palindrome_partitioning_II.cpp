#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<int> D(len + 1, 0);
        for (int i = 0; i <= len; i++) {
            D[i] = len - i - 1;
        }
        vector<vector<bool> > P(len, vector<bool>(len, false));
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] == s[j] && (j - i < 2 || P[i + 1][j - 1])) {
                    P[i][j] = true;
                    D[i] = min(D[i], D[j + 1] + 1);
                    //cout << "D[" << i << "] : " << D[i] << endl;
                }
            }
        }
        return D[0];
    }
};

int main() {
    string input;
    cin >> input;
    Solution test;
    cout << test.minCut(input) << endl;
    return 0;
}
