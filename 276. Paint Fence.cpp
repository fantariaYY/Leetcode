class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0 || k == 0)
        {
            return 0;
        }
        
        int prev2 = k, prev1 = k * k;
        
        if(n == 1)
        {
            return prev2;
        }
        
        if(n == 2)
        {
            return prev1;
        }
        
        int curr = 0;
        for(int i = 3;i <= n; i++)
        {
            curr = (prev2 + prev1) * (k - 1);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return curr;
    }
};