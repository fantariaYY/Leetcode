class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> opt(n, vector<int>(m, 0));
        
        opt[0][0] = grid[0][0];
        for(int i = 1;i < n; ++i)
        {
            opt[i][0] = opt[i - 1][0] + grid[i][0];
        }
        
        for(int j = 1;j < m; ++j)
        {
            opt[0][j] = opt[0][j - 1] + grid[0][j];
        }
        
        for(int i = 1;i < n; ++i)
        {
            for(int j = 1;j < m; ++j)
            {
                opt[i][j] = min(opt[i - 1][j], opt[i][j - 1]) + grid[i][j];
            }
        }
        
        return opt[n - 1][m - 1];
    }
};