#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            len = s.size();
            if (len == 0) {
                return ret;
            }
            vector<int> ip;
            helper(s, ip, len - 1, 0);
            return ret;
        }
    private:
        void helper(string &s, vector<int> ip, int pos, int segment) {
            if (segment == 4 && pos == -1) {
                string tmp;
                for (int i = 3; i >= 0; i--) {
                    char buf[10];
                    if (i == 0) {
                        sprintf(buf, "%d", ip[i]);
                    }
                    else
                        sprintf(buf, "%d%c", ip[i], '.');
                    tmp.append(buf);
                }
                ret.push_back(tmp);
            }
            else if (segment == 4)
                return;
            else {
                int i = 1;
                string tmp;
                while (pos >= 0 && i <= 3) {
                    tmp = s.substr(pos, i);
                    if (tmp.size() > 1 && tmp[0] == '0') {
                        pos--;
                        i++;
                        continue;
                    }
                    int addr = atoi(tmp.c_str());
                    if (addr <= 255) {
                        ip.push_back(addr);
                        helper(s, ip, pos - 1, segment + 1);
                        ip.pop_back();
                        pos--;
                        i++;
                    }
                    else
                        break;
                }
            }
        }
        vector<string> ret;
        int len;
};

int main() {
    string s;
    cin >> s;
    Solution test;
    vector<string> ret;
    ret = test.restoreIpAddresses(s);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }

    return 0;
}
