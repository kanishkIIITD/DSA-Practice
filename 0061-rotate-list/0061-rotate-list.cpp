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
    int getLen(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0)
            return head;
        if(!head || !head->next)
            return head;
        int len = getLen(head);
        k = k % len;
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            if(count == len - k)
                break;
            temp = temp->next;
        }
        ListNode* tail = temp;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = head;
        ListNode* newHead = temp->next;
        temp->next = NULL;
        return newHead;
    }
};