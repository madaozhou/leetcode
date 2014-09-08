#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
            return 1;
        int size = min(m, n);
        int bigger = max(m, n);
        vector<int> f(size, 1);
        for (int i = 1; i < bigger; i++) {
            for (int j = 1; j < size; j++) {
                f[j] += f[j - 1];
            }
        }
        return f[size - 1];
    }
};
