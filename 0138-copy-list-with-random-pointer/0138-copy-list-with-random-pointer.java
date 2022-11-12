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
        // Approach 2
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
        
        Map<Node, Node> mapping = new HashMap<Node, Node>();
        
        Node oldNode = head;
        Node newNode = cloneHead;
        while(oldNode != null){
            mapping.put(oldNode, newNode);
            oldNode = oldNode.next;
            newNode = newNode.next;
        }
        
        oldNode = head;
        newNode = cloneHead;
        while(oldNode != null){
            newNode.random = mapping.get(oldNode.random);
            oldNode = oldNode.next;
            newNode = newNode.next;
        }
        
        return cloneHead;
    }
}