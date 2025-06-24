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
    void inorder(TreeNode* root,int count,int &ans){
        if(root==NULL){
            ans=max(ans,count);
            return;
        }
        count++;
        inorder(root->left,count,ans);
        inorder(root->right,count,ans);
    }


    int maxDepth(TreeNode* root) {
        int count=0;
        int ans=0;
        inorder(root,count,ans);
        return ans;
    }
};