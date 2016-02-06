class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty())
        {
            return 0;
        }
        
        int n = costs.size(), k = costs[0].size();
        
        vector<int> opt(k, 0);
        
        int min1 = 0, min2 = 0;
        for(int i = 0;i < n;i++)
        {
            int tmpMin1 = min1, tmpMin2 = min2;
            min1 = INT_MAX;
            min2 = INT_MAX;
            
            for(int j = 0;j < k;j++)
            {
                if(opt[j] != tmpMin1 || tmpMin1 == tmpMin2)
                {
                    opt[j] = tmpMin1 + costs[i][j];
                }
                else
                {
                    opt[j] = tmpMin2 + costs[i][j];
                }
                
                if(opt[j] <= min1)
                {
                    min2 = min1;
                    min1 = opt[j];
                }
                else
                {
                    if(opt[j] < min2)
                    {
                        min2 = opt[j];
                    }
                }
            }
        }
        
        return min1;
    }
};