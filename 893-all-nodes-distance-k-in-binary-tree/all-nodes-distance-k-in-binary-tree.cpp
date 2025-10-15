/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void levelOrder(TreeNode* root, TreeNode* target, int k,unordered_map<TreeNode*,TreeNode*>&par){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front->left){
                par[front->left]=front;
                q.push(front->left);
            }
            
            if(front->right){
                par[front->right]=front;
                q.push(front->right);
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0){
            return {target->val};
        }
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        unordered_map<TreeNode*,TreeNode*>par;
        levelOrder(root,target,k,par);
        q.push(target);
        vis[target]=true;
        q.push(new TreeNode(-1));
        vector<int>ans;
        while(!q.empty() ){
            TreeNode*front=q.front();
            vis[front]=true;
            q.pop();
            if(front->val==-1){
                k--;
                if(k==0){
                    break;
                } 
                if(q.size()>0)
                q.push(new TreeNode(-1));
            }
            else{
                if(par[front] && !vis[par[front]]){
                    q.push(par[front]);
                }
                if(front->left && !vis[front->left]){
                    q.push(front->left);
                }
                if(front->right && !vis[front->right]){
                    q.push(front->right);
                }
            }
        }
        while(!q.empty()){
            if(q.front()->val!=-1){
                ans.push_back(q.front()->val);
            }
            q.pop();
        }
        return ans;   
    }
};