class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        
        long long int m = s + (e - s)/2;
        long long int ans = 0;
        
        while(s <= e){
            
            if(m*m == x)
                return m;
            
            else if(m*m > x)
                e = m - 1;
            
            else{
                
                ans = m;
                s = m + 1;
                
            } 
            
            m = s + (e - s)/2;
            
        }
        
        return ans;
    }
};