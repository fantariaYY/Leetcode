class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> sol;
        helper(result, sol, n, 2);
        
        return result;
    }
    
    void helper(vector<vector<int>> &result, vector<int> &sol, int n, int div)
    {
        if(n == 1)
        {
            if(sol.size() > 1)
            {
                result.push_back(sol);
                return;
            }
        }
        
        for(int i = div;i <= n ; ++i)
        {
            if(n % i == 0)
            {
                sol.push_back(i);
                helper(result, sol, n / i, i);
                sol.pop_back();
            }
        }
    }
};