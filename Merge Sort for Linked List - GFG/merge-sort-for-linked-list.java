//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

class Driverclass
{
    
    public static void main (String[] args) 
    {
        Scanner sc= new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            Node head = new Node(sc.nextInt());
            Node tail = head;
            while(n-- > 1){
		        tail.next = new Node(sc.nextInt());
		        tail = tail.next;
		    }
		   
		      head = new Solution().mergeSort(head);
		     printList(head);
		    System.out.println();
        }
    }
    public static void printList(Node head)
    {
        if(head == null)
           return;
           
        Node temp = head;
        while(temp != null)
        {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}



// } Driver Code Ends


//User function Template for Java
/*
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        this.data = key;
        next = null;
    }
} */

class Solution
{
    //Function to sort the given linked list using Merge Sort.
    
    public Node getMiddle(Node head){
        Node slow = head;
        Node fast = head.next;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    
     Node mergeSort(Node head)
    {
        // add your code here
        if(head == null || head.next == null)
            return head;
        
        Node mid = getMiddle(head);
        
        Node left = head;
        Node right = mid.next;
        mid.next = null;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        if(left.data <= right.data)
            return sort(left, right);
        
        else
            return sort(right, left);
    }
    
    public Node sort(Node left , Node right){
        if(left == null)
            return right;
        if(right == null)
            return left;
            
        Node cur1 = left;
        Node next = left.next;
        if(next == null){
            cur1.next = right;
        }
        Node cur2 = right;
        Node next2 = cur2.next;
        while(cur2 != null && next != null){
            
            if(cur1.data <= cur2.data && cur2.data <= next.data){
                cur1.next = cur2;
                next2 = cur2.next;
                cur2.next = next;
                cur1 = cur2;
                cur2 = next2;
            }
            else{
                cur1 = next;
                next = next.next;
                if(next == null){
                    cur1.next = cur2;
                    return left;
                }
            }
            
        }
        return left;
    }
}


