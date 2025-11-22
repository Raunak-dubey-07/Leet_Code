/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root != NULL) {
            q.push(root);
            q.push(new Node(1001));
        }
        vector<Node*> ans;

        while (!q.empty()) {
            if (q.front()->val == 1001) {
                ans.push_back(q.front());
                q.pop();
                if (q.size() > 0)
                    q.push(new Node(1001));
            } else {
                ans.push_back(q.front());
                Node* front = q.front();
                q.pop();
                if (front->left != NULL)
                    q.push(front->left);
                if (front->right != NULL)
                    q.push(front->right);
            }
        }
        if (ans.size() == 0)
            return NULL;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i]->val != 1001) {
                if (ans[i + 1]->val == 1001) {
                    //cout << ans[i] << endl;
                    ans[i]->next = NULL;
                } else {
                    //cout << ans[i] << " " << ans[i + 1] << endl;
                    ans[i]->next = ans[i + 1];
                }
            }
        }
        return ans[0];
    }
};