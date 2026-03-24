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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        ListNode* fast = head;
        while(i != n){
            i++;
            fast = fast->next;
        }
        if(fast == nullptr)
            return head->next;
        ListNode* slow = head;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* next = slow->next;
        slow->next = next->next;
        delete next;
        return head;
    }
};