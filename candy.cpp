#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public :
        int candy(vector<int> &ratings) {
            int len = ratings.size();
            int candy[len];
            int sum = 0;
            candy[0] = 1;
            for (int i = 1; i < len; i++) {
                if (ratings[i] > ratings[i - 1]) {
                    candy[i] = candy[i - 1] + 1;
                }
                else
                    candy[i] = 1;
            }
            for (int i = len - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1]) {
                    candy[i] = candy[i + 1] + 1 > candy[i] ? candy[i + 1] + 1 : candy[i];
                }
                sum += candy[i];
            }
            if (len > 0) {
                sum += candy[len - 1];
            }
            return sum;
        }
};
