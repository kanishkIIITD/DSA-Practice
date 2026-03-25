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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        int count = 0;
        ListNode* kthNode = head;
        while(count != k && kthNode){
            count++;
            kthNode = kthNode->next;
        }
        if(count < k)
            return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* forw = NULL;
        for (int i = 0; i < k; i++) {
            forw = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forw;
        }
        ListNode* newNode = reverseKGroup(forw, k);
        head->next = newNode;
        return prev;        
    }
};