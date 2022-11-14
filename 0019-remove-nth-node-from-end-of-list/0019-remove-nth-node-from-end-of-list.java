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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int size = 0;
        ListNode temp = head;
        while(temp != null){
            temp = temp.next;
            size ++;
        }
        if(n == 1 && size ==1)
            return null;
        
        if(n == size){
            return head.next;
        }
        
        int count = 1;
        temp = head;
        int num = (size - n + 1);
        while(temp != null){
            
            if(count == num-1){
                temp.next = temp.next.next;
                break;
            }
            temp = temp.next;
            count++;
        }
        return head;
    }
}