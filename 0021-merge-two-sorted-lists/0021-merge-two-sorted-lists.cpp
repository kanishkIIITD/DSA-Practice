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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;

        ListNode* prev1 = NULL;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                prev1 = temp1;
                temp1 = temp1->next;
            }
            else{
                if(prev1)
                    prev1->next = temp2;
                else
                    list1 = temp2;
                ListNode* next2 = temp2->next;
                temp2->next = temp1;
                prev1 = temp2;
                temp2 = next2;
            }
        }
        while(temp2){
            prev1->next = temp2;
            prev1 = temp2;
            temp2 = temp2->next;
        }
        return list1;
    }
};