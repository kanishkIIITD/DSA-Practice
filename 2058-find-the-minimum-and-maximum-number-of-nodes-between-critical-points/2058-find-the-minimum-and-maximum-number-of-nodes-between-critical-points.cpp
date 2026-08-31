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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return {-1, -1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        int i1 = -1, i2 = -1, i3 = -1;
        int mini = INT_MAX;
        int count = 1;
        while(curr->next){
            if((curr->val > prev->val && curr->val > curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val)){
                if(i1 == -1)
                    i1 = count;
                else if(i2 == -1){
                    i2 = count;
                    mini = min(mini, i2-i1);
                }
                else if(i3 == -1){
                    i3 = count;
                    mini = min(mini, i3 - i2);
                }
                else{
                    i2 = i3;
                    i3 = count;
                    mini = min(mini, i3 - i2);
                }
            }
            count++;
            prev = curr;
            curr = curr->next;
        }
        int maxi;
        if(i3 != -1)
            maxi = i3 - i1;
        else if(i2 != -1)
            maxi = i2 - i1;
        else
            maxi = -1;
        mini = mini == INT_MAX ? -1 : mini;
        return {mini, maxi};
    }
};