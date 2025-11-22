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
    void genans(TreeNode* root, int targetSum,vector<vector<int>>&res,vector<int>ans,int sum){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            sum+=root->val;
            ans.push_back(root->val);
            if(sum==targetSum){
                res.push_back(ans);
            }
            return;

        }
        sum+=root->val;
        ans.push_back(root->val);
        genans(root->left,targetSum,res,ans,sum);
         genans(root->right,targetSum,res,ans,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return { };
        }
        vector<int>ans;
        vector<vector<int>>res;
        int sum=0;
        genans(root,targetSum,res,ans,sum);
        return res;
    }
};