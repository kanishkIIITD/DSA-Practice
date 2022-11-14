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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
        return null;
        }
        // Use the 0-th list as a return list
        for (int i = 1; i < lists.length; ++i) {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }

        return lists[0];
    }
    
    public ListNode solve(ListNode list1, ListNode list2){
        ListNode cur = list1;
        ListNode next = list1.next;
        if(next == null){
            cur.next = list2;
        }
        ListNode temp = list2;
        ListNode next2 = null;
        while(temp != null && next != null){
            
            if(cur.val <= temp.val && temp.val <= next.val){
                cur.next = temp;
                next2 = temp.next;
                temp.next = next;
                cur = temp;
                temp = next2;
            }
            else{
                cur = next;
                next = next.next;
                if(next == null){
                    cur.next = temp;
                    return list1;
                }
            }
            
        }
        return list1;
    }
    
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
        if(list1 == null)
            return list2;
        if(list2 == null)
            return list1;
        
        if(list1.val <= list2.val){
            return solve(list1, list2);
        }
        
        else{
            return solve(list2, list1);
        } 
    }
}