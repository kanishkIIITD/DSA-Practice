//{ Driver Code Starts
import java.util.Scanner;
import java.util.Stack;
class SortedStack{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0){
			Stack<Integer> s=new Stack<>();
			int n=sc.nextInt();
			while(n-->0)
			s.push(sc.nextInt());
			GfG g=new GfG();
			Stack<Integer> a=g.sort(s);
			while(!a.empty()){
				System.out.print(a.peek()+" ");
				a.pop();
			}
			System.out.println();
		}
	}
}
// } Driver Code Ends


/*Complete the function below*/
class GfG{
    public Stack<Integer> sortedInsert(Stack<Integer> s, int x){
        if(s.empty()){
            s.push(x);
            return s;
        }
        int top = s.peek();
        if(top < x){
            s.push(x);
            return s;
        }
        s.pop();
        s = sortedInsert(s, x);
        
        s.push(top);
        return s;
        
    }
	public Stack<Integer> sort(Stack<Integer> s)
	{
		//add code here.
		if(s.empty()){
		    return s;
		}
		int top = s.peek();
		s.pop();
		s = sort(s);
		
		return sortedInsert(s,top);
	}
}