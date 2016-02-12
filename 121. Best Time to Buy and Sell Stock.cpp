class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int minimum = INT_MAX;
        for(int i = 0;i < prices.size();i++)
        {
            minimum = min(minimum, prices[i]);
            result = max(result, prices[i] - minimum);
        }
        
        return result;
    }
};