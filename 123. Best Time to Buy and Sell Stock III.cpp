class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
        {
            return 0;
        }
        
        vector<int> left(n, 0);
        int minimum = INT_MAX;
        for(int i = 0;i < n; ++i)
        {
            minimum = min(minimum, prices[i]);
            left[i] = max((i > 0 ? left[i - 1] : 0), prices[i] - minimum);
        }
        
        vector<int> right(n, 0);
        int maximum = INT_MIN;
        for(int i = n - 1;i >= 0; --i)
        {
            maximum = max(maximum, prices[i]);
            right[i] = max((i < n - 1 ? right[i + 1] : 0), maximum - prices[i]);
        }
        
        int result = right[0];
        for(int i = 0;i < n - 1;i++)
        {
            result = max(result, left[i] + right[i + 1]);
        }
        
        return result;
    }
};