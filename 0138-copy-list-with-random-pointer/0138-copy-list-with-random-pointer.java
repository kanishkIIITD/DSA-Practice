/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        // Approach 3
        Node cloneHead = null;
        Node cloneTail = null;
        
        Node temp = head;
        while(temp != null){
            Node node = new Node(temp.val);
            if(cloneHead == null){
                cloneHead = node;
                cloneTail = node;
            }
            else{
                cloneTail.next = node;
                cloneTail = node;
            }
            temp = temp.next;
        }
        
        Node originalNode = head;
        Node next1 = null;
        Node cloneNode = cloneHead;
        Node next2 = null;
        while(cloneNode != null){
            
            next1 = originalNode.next;
            originalNode.next = cloneNode;
            originalNode = next1;
            
            next2 = cloneNode.next;
            cloneNode.next = originalNode;
            cloneNode = next2;
            
        }
        
        temp = head;
        while(temp != null){
            if(temp.random != null)
                temp.next.random = temp.random.next;
            temp = temp.next.next;
        }
        
        originalNode = head;
        if(originalNode != null)
            cloneNode = originalNode.next;
        while(originalNode != null){
            originalNode.next = cloneNode.next;
            originalNode = originalNode.next;
            
            if(originalNode != null){
                cloneNode.next = originalNode.next;
                cloneNode = cloneNode.next;
            }
        }
        
        return cloneHead;
    }
}