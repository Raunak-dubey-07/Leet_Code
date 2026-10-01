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
class FindElements {
public:
    TreeNode*dummyroot;
    bool Inorder(TreeNode*root,int target){
        if(root==NULL){
            return false;
        }
        if(root->val==target){
            return true;
        }
        if(Inorder(root->left,target) || Inorder(root->right,target)){
            return true;
        }
        return false;
    }
    void fillTree(TreeNode*root){
        if(root==NULL){
            return;
        }
        if(root->left){
            root->left->val=2*root->val+1;
            fillTree(root->left);
        }
        
        if(root->right){
            root->right->val=2*root->val+2;
            fillTree(root->right);
        }
    }
    FindElements(TreeNode* root) {
        dummyroot=root;
        root->val=0;
        fillTree(root);
    }
    
    bool find(int target) {
        if(Inorder(dummyroot,target)){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */