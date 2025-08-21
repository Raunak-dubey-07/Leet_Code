/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void sorted(TreeNode*root,vector<TreeNode*>&arr){
        if(root==NULL){
            return;
        }
        sorted(root->left,arr);
        arr.push_back(root);
        sorted(root->right,arr);
    }
    TreeNode* sortedArrayToBST(int start, int end,vector<TreeNode*>sorted) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = sorted[mid];
        root->left = sortedArrayToBST(start, mid - 1,sorted);
        root->right = sortedArrayToBST(mid + 1, end,sorted);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>arr;
        sorted(root,arr);
        int n=arr.size();
        return sortedArrayToBST(0,n-1,arr);
    }
};