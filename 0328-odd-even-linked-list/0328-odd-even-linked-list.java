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
    public ListNode oddEvenList(ListNode head) {
        // ListNode temp = head;
        // ListNode inter = head.next;
        // while(temp != null || temp.next != null){
        //     ListNode next = temp.next;
        //     temp.next = temp.next.next;
        //     temp = next;
        // }
        // temp.next = inter;
        // return head;
        
        
        if (head != null) {
    
            ListNode odd = head, even = head.next, evenHead = even; 
    
            while (even != null && even.next != null) {
                odd.next = odd.next.next; 
                even.next = even.next.next; 
                odd = odd.next;
                even = even.next;
            }
            odd.next = evenHead; 
        }
        return head;
    }
}