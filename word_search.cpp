#include <vector>
#include <string>
#include <iostream>
#include <utility>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        row = board.size();
        col = board[0].size();
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (helper(board, visited, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
private:
    bool helper(vector<vector<char> > &board, vector<vector<bool> > &visited,
            string &word, int pos, int row_pos, int col_pos) {
        if (pos == word.size())
            return true;
        if (row_pos >= row || row_pos < 0 || col_pos >= col || col_pos < 0)
            return false;
        if (visited[row_pos][col_pos] || board[row_pos][col_pos] != word[pos])
            return false;
        visited[row_pos][col_pos] = true;
        bool tmp = helper(board, visited, word, pos + 1, row_pos - 1, col_pos)
            || helper(board, visited, word, pos + 1, row_pos, col_pos - 1)
            || helper(board, visited, word, pos + 1, row_pos + 1, col_pos)
            || helper(board, visited, word, pos + 1, row_pos, col_pos + 1);
        visited[row_pos][col_pos] = false;
        return tmp;
    }
    int row;
    int col;

};
