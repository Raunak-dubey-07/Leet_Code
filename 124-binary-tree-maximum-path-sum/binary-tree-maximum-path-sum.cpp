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
    int maxheight(TreeNode* root, int &sum,int currsum){
        if(root==NULL){
            sum=max(sum,currsum);
            return 0;
        }
        currsum+=root->val;
        sum=max(sum,currsum);
        maxheight(root->left,sum,currsum);
        maxheight(root->right,sum,currsum);
        return sum;
    }
    int maxdia(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int sum=0;
        int lefth=maxheight(root->left,sum,0);
        cout<<root->val<<" "<<lefth<<endl;
        sum=0;
        int righth=maxheight(root->right,sum,0);
        cout<<root->val<<" "<<righth<<endl;
        return root->val+lefth+righth;
    }
    void inorder(TreeNode*root,int &sum){
        if(root==NULL){
            return;
        }
        sum=max(sum,maxdia(root));
        inorder(root->left,sum);
        inorder(root->right,sum); 
    }
    int maxPathSum(TreeNode* root) {
       int sum=INT_MIN;
       inorder(root,sum);
       return sum;
    }
};