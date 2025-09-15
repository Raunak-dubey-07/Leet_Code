/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode *reverseList(ListNode *head) {

    ListNode *curr = head, *prev = nullptr, *next;

    // Traverse all the nodes of Linked List
    while (curr != nullptr) {

        // Store next
        next = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }

    return prev;
}

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        ListNode*top=reverseList(head);
        stack<long long>st;
        while(top){
            
            while(!st.empty() && st.top()<=top->val){
                st.pop();
            }
            if(!st.empty()){
                ans.push_back(st.top());
            }else{
                //cout<<top->val<<endl;
                ans.push_back(0);
            }
            st.push(top->val);
            top=top->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};