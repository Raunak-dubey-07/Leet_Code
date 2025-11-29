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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int res = 0;
        long long maxi = LLONG_MIN;
        while (!q.empty()) {
            if (q.front() == NULL) {
                q.pop();
                res = maxi;
                maxi = LLONG_MIN;
                if (q.size() > 0) {
                    q.push(NULL);
                }
            } else {
                if (maxi == LLONG_MIN) {
                    cout<<q.front()->val<<endl;
                    maxi = q.front()->val;
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
        }
        return res;
    }
};