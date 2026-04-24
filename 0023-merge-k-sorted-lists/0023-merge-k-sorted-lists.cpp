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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyNode = new ListNode(-1);
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        ListNode* temp = dummyNode;
        while(!pq.empty()){
            int value = pq.top().first;
            ListNode* curr = pq.top().second;
            pq.pop();
            temp->next = curr;
            temp = curr;
            if(curr->next)
                pq.push({curr->next->val, curr->next});
        }
        return dummyNode->next;
    }
};