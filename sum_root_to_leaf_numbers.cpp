#include <iostream>
#include <vector>

using namespace std;

/*
 *Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int total_sum = 0;
        if (root)
            helper(root, 0, total_sum);
        return total_sum;
    }
private:
    void helper(TreeNode *node, int path_sum, int &total_sum) {
        path_sum = path_sum * 10 + node->val;
        if (node->left)
            helper(node->left, path_sum, total_sum);
        if (node->right)
            helper(node->right, path_sum, total_sum);
        if (!node->left && !node->right)
            total_sum += path_sum;
    }
};

