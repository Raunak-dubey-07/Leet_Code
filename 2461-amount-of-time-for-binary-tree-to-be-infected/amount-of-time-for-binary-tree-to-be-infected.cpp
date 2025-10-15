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
 void levelOrder(TreeNode* root, TreeNode* target,unordered_map<TreeNode*,TreeNode*>&par){
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
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*front=q.front();
            q.pop();
            if(front->val==start){
                target=front;
                break;
            }
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        q = queue<TreeNode*>();
        unordered_map<TreeNode*,bool>vis;
        unordered_map<TreeNode*,TreeNode*>par;
        levelOrder(root,target,par);
        q.push(target);
        vis[target]=true;
        q.push(new TreeNode(-1));
        int time=0;
        vector<int>ans;
        while(!q.empty() ){
            TreeNode*front=q.front();
            vis[front]=true;
            q.pop();
            if(front->val==-1){
                time++; 
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
        return time-1;
        
    }
};