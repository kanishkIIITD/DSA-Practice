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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1. Create a dummy node to anchor the start of our new list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        
        // 2. A single loop that runs as long as there is ANY work left to do
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; 
            
            // If l1 has a node, add its value and move forward
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // If l2 has a node, add its value and move forward
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // 3. Create the new node and calculate the next carry
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            
            curr = curr->next;
        }
        
        // 4. Our actual result starts immediately after the dummy node
        ListNode* head = dummy->next;
        delete dummy; // Clean up our temporary dummy node
        
        return head;
    }
};