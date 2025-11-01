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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mapping;
        for(int i=0;i<nums.size();i++){
            mapping[nums[i]]=1;
        }
        ListNode* temp = head;
        ListNode* forword = NULL;
        ListNode* prev = NULL;
            while (temp != NULL) {
                forword = temp->next;
                if (mapping[temp->val]==1 && prev == NULL) {
                    ListNode*d=temp;
                    temp = temp->next;
                    head=temp;
                }
                else if (mapping[temp->val]==1 ) {
                    ListNode*d=temp;
                    prev->next = forword;
                    temp=forword;
                }
                 else {
                    prev = temp;
                    temp = forword;
                }
            }
        
        return head;
    }
};