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
    public ListNode reverse(ListNode head){
        
        ListNode prev = null;
        ListNode cur = head;
        ListNode next = null;
        while(cur != null){
            next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next; 
        }
        return prev;
    }
    
    public ListNode add(ListNode l1, ListNode l2){
        int carry = 0;
        ListNode ansHead = null;
        ListNode ansTail = null;
        
        while(l1 != null || l2 != null || carry != 0){
            int val1 = 0;
            if(l1 != null)
                val1 = l1.val;
            int val2 = 0;
            if(l2 != null)
                val2 = l2.val;
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            //insert(ansHead, ansTail, digit);
            
            
            ListNode node = new ListNode(digit);
            if(ansHead == null){
                ansHead = node;
                ansTail = node;
                
            }
            else{
                ansTail.next = node;
                ansTail = node;
            }
            
            
            carry = sum / 10;
            
            if(l1 != null)
                l1 = l1.next;
            if(l2 != null)
                l2 = l2.next;
        }

        return ansHead;
    }
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = add(l1, l2);
        
        return ans;
    }
}