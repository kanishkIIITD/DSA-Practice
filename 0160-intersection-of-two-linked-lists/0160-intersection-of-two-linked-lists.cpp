/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1){
            len1++;
            t1 = t1->next;
        }
        while(t2){
            len2++;
            t2 = t2->next;
        }
        t1 = headA;
        t2 = headB;

        if(len1 > len2){
            while(len1 - len2 != 0){
                t1 = t1->next;
                len1--;
            }
        }
        else if(len2 > len1){
            while(len2 - len1 != 0){
                t2 = t2->next;
                len2--;
            }
        }
        while(t1){
            if(t1 == t2)
                return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        return NULL;
    }
};