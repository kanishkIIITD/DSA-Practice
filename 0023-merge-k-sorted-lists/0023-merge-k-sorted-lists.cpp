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
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        while(t1 && t2){
            if(t1->val <= t2->val){
                temp->next = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }
        if(t1)
            temp->next = t1;
        if(t2)
            temp->next = t2;
        return dNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int interval = 1;
        int n = lists.size();
        
        while (interval < n) {
            for (int i = 0; i + interval < n; i += interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }
};