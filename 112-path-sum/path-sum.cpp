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
    bool inorder(TreeNode*root,int target){
        if(root==NULL){
            return false;
        }
        if(root->right==NULL && root->left==NULL && target==root->val){
            return true;
        }
        
        bool left=inorder(root->left,target-root->val);
        bool right=inorder(root->right,target-root->val);
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        return inorder(root,targetSum);
        return false;
        
    }
};