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
    void countPath(TreeNode*root,int target,vector<int>Path,int &count){
        if(root==NULL){
            return;
        }
        Path.push_back(root->val);
        countPath(root->left,target,Path,count);
        countPath(root->right,target,Path,count);
        int size=Path.size();
        long long sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=Path[i];
            if(sum==target){
                count++;
            }
        }




    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int >Path;
        int ans=0;
        countPath(root,targetSum,Path,ans);
        return ans;
    }
};