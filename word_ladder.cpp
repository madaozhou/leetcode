class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> wordQueue;
        queue<int> ret;
        int length = start.length();
        wordQueue.push(start);
        ret.push(1);
        while (!wordQueue.empty()) {
            string word(wordQueue.front());
            wordQueue.pop();
            int len = ret.front();
            ret.pop();
            for (int i = 0; i < length; i++) {
                char tmp = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (word == end) {
                        return len + 1;
                    }
                    if (dict.find(word) != dict.end()) {
                        wordQueue.push(word);
                        ret.push(len + 1);
                        dict.erase(word);
                    }
                    word[i] = tmp;
                }
            }
        }
        return 0;
    }
};
