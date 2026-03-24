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
    int getLLlen(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLLlen(head);
        if(len - n == 0)
            return head->next;
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            if(count == len - n){
                ListNode* next = temp->next;
                temp->next = next->next;
                next->next = nullptr;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};