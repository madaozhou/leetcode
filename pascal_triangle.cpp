#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        if (numRows == 0) return ret;
        ret.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            vector<int> tmp;
            tmp.resize(i + 1);
            if (ret[i - 1].size() > 1) {
                for (int j = 1; j <= (i + 1) / 2; j++) {
                    tmp[j] = tmp[i - j] = ret[i - 1][j - 1] + ret[i - 1][j];
                }
            }
            tmp[0] = tmp[i] = 1;
            /*
             *for (int m = 0; m <= i; m++) {
             *    cout << tmp[m] << ' ';
             *}
             *cout << endl;
             */
            ret.push_back(tmp);
        }
        return ret;
    }
};

int main() {
    int numRows = 0;
    cin >> numRows;
    Solution test;
    test.generate(numRows);
    return 0;
}
