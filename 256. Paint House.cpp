class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int r = 0, b = 0, g = 0;
        
        for(int i = 0;i < n;++i)
        {
            int tmpr = r, tmpb = b, tmpg = g;
            r = costs[i][0] + min(tmpb, tmpg);
            b = costs[i][1] + min(tmpr, tmpg);
            g = costs[i][2] + min(tmpr, tmpb);
        }
        
        return min(r, min(b, g));
    }
};