/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildPerfectTree(vector<int> &arr, int i) {
    if(i >= arr.size())
        return NULL;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = buildPerfectTree(arr, 2*i + 1);
    root->right = buildPerfectTree(arr, 2*i + 2);
    return root;
}

    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        bool level = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int> ans(n, 0);
            for (int i = 0; i < n; i++) {
                if (level) {
                    ans[i] = q.front()->val;
                } else {
                    ans[n - i-1] = q.front()->val;
                }
                TreeNode* front = q.front();
                q.pop();
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            level = !level;
            for (int i = 0; i < n; i++) {
                res.push_back(ans[i]);
            }
        }

       return buildPerfectTree(res, 0);
    }
};