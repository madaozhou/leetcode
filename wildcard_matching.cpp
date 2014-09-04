#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            const char *sPos = NULL;
            const char *pPos = NULL;
            while (*s) {
                if (*s == *p || *p == '?') {
                    s++;
                    p++;
                    continue;
                }
                if (*p == '*') {
                    pPos = p++;
                    sPos = s;
                    continue;
                }
                if (pPos) {
                    p = pPos + 1;
                    s = ++sPos;
                    continue;
                }
                return false;
            }
            while (*p == '*') {
                p++;
            }
            return !*p;
        }
};
