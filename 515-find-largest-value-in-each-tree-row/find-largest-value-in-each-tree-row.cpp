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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>ans;
        int maxi=INT_MIN;
        while(!q.empty()){
            if(q.front()==NULL){
                 q.pop();
                ans.push_back(maxi);
                maxi=INT_MIN;
                if(q.size()>0){
                    q.push(NULL);
                }
               
            }
            else{
            maxi=max(maxi,q.front()->val);
            TreeNode*front=q.front();
            q.pop();
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
            }
        }
        return ans;
        
    }
};