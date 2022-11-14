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
    // Iterative Solution
    // public ListNode reverseList(ListNode head) {
    //     ListNode cur = head;
    //     ListNode prev = null;
    //     while(cur != null){
    //         ListNode nexxt = cur.next;
    //         cur.next = prev;
    //         prev = cur;
    //         cur = nexxt;
    //     }
    //     return prev;
    // }
    
    public ListNode reverseList(ListNode head) {
    /* recursive solution */
        ListNode prev = null;
        return reverseListInt(head, prev);
    }

    private ListNode reverseListInt(ListNode head, ListNode newHead) {
        if (head == null)
            return newHead;
        ListNode next = head.next;
        head.next = newHead;
        return reverseListInt(next, head);
    }
}