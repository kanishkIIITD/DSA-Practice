//{ Driver Code Starts
import java.util.Scanner;
import java.util.Stack;
class SpeStack{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0){
			int n=sc.nextInt();
			Stack<Integer> s=new Stack<>();
			GfG g=new GfG();
			while(!g.isEmpty(s)){
			    g.pop(s);
			}
			while(!g.isFull(s,n)){
				g.push(sc.nextInt(),s);
			}
		System.out.println(g.min(s));
		}
	}
}
// } Driver Code Ends


/*Complete the function(s) below*/
class GfG{
    int min = Integer.MAX_VALUE;
    Stack<Integer> stack = new Stack<Integer>();
    int size = 0;
    
	public void push(int x,Stack<Integer> s)
	{
	    //add code here.
	    if (x <= min) {
            stack.push(min);
            min = x;
        }
        stack.push(x);
        size++;
	}
	public int pop(Stack<Integer> s)
    {
        //add code here.
        int pop = stack.pop();
        size--;
        if (pop == min) {
            min = stack.pop();
            size--;
            return min;
        }
        else{
            return pop;
        }
        
	}
	public int min(Stack<Integer> s)
    {
        //add code here.
        return min;
	}
	public boolean isFull(Stack<Integer>s, int n)
    {
        //add code here.
        return size == n;
        
	}
	public boolean isEmpty(Stack<Integer>s)
    {
        //add code here.
        return stack.isEmpty();
	}
}