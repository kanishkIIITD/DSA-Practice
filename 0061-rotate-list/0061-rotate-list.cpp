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
    pair<int, ListNode*> findLen(ListNode* head){
        int len = 1;
        while(head->next){
            head = head->next;
            len++;
        }
        return {len, head};
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        auto [n, tail] = findLen(head);
        k = k % n;
        if(k == 0)
            return head;
        ListNode* temp = head;
        int count = n - k;
        while(temp && count > 1){
            temp = temp->next;
            count--;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};