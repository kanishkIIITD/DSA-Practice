/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        // Approach 1 using size of the linked list
//         int size = 0;
//         ListNode temp = head;
//         while(temp != null){
//             size++;
//             temp = temp.next;
//         }
//         ListNode newHead = head;
        
//         for(int i = 0; i < size/2; i++){
//             newHead = newHead.next;
//         }
//         return newHead;
        
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null){
            if(fast.next == null){
                break;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}